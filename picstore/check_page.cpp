#include "check_page.h"
#include "ui_check_page.h"

check_page::check_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::check_page)
{
    ui->setupUi(this);
    Get_pics();

}

check_page::Get_pics()
{
    QString str = QString("SELECT * FROM pcheck");//查询操作
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    if(query.next()){
        int temp_num;
        QString temp_addr;
        QString temp_artist;
        QString temp_name;
        QString temp_time;
        int temp_hot;
        temp_num = query.value(0).toInt();
        temp_addr = query.value(1).toString();
        temp_artist = query.value(2).toString();
        temp_name = query.value(3).toString();
        temp_time = query.value(4).toString();
        temp_hot =  query.value(5).toInt();
        picture = new pic_info();
        picture->Set_pic_info(temp_num,temp_addr,temp_artist,temp_name,temp_time,temp_hot);

        QSize laSize1=ui->show->size();
        QImage image1;
        image1.load(picture->addr);
        image1 = image1.scaled(laSize1,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        //qDebug()<<"bbb";
        ui->show->setPixmap(QPixmap::fromImage(image1));
    }else{
        ui->show->setText("无待审核图片");
    }
}

check_page::~check_page()
{
    delete ui;
}

void check_page::on_pass_clicked()
{
    int total_num;
    QString str = QString("SELECT * FROM P ORDER BY NUM DESC");
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    if(query.next()){
        total_num = query.value(0).toInt();
    }
    else{
        total_num = 0;
    }

    str = QString("insert into p(num,addr,artist,name,time,hot) values(%1,'%2','%3','%4','%5',%6)")\
            .arg(QString::number(total_num+1),picture->addr,picture->artist\
                 ,picture->name,picture->time,"0");
    qDebug()<<str;
    query.exec(str);

    str = QString("DELETE FROM pcheck WHERE num = %1").arg(picture->num);
    query.exec(str);

    Get_pics();
}
