#include "user_page.h"
#include "ui_user_page.h"

user_page::user_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_page)
{
    ui->setupUi(this);
}

user_page::user_page(int user_number, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_page)
{
    ui->setupUi(this);
    user_num = user_number;
    QString str = QString("SELECT * FROM ac WHERE id = %1 ").arg(user_num);//查询操作
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    query.next();

    QString name;
    QString type_str;
    int type;
    name = query.value(1).toString();
    type = query.value(3).toInt();
    switch (type) {
    case 0:
        type_str = "游客";
        break;
    case 1:
        type_str = "创作者";
        break;
    case 2:
        type_str = "管理员";
        break;
    default:
        break;
    }
    ui->user_name->setText(name);
    ui->user_mode->setText(type_str);
    ui->user_id->setText(QString::number(user_num));

    str = QString("SELECT COUNT(1) FROM ul WHERE unum = %1 ").arg(user_num);//查询操作
    query.exec(str);
    if(query.next()){
        like_num = query.value(0).toInt();
    }
    ui->pre_pic->setEnabled(false);
    ui->pre_pic_2->setEnabled(false);
    if(pic_base > like_num){
        ui->next_pic->setEnabled(false);
        ui->next_pic_2->setEnabled(false);
    }
    str = QString("SELECT * FROM ul WHERE unum = %1 ").arg(user_num);//查询操作
    query.exec(str);
    for(int i=0;i<like_num;i++){
        if(!query.next()){
            break;
        };
        int pnum = query.value(1).toInt();
        qDebug()<<"pnum" + QString::number(pnum);
        QString str2 = QString("SELECT * FROM p WHERE num = %1 ").arg(pnum);//查询操作
        qDebug()<<str2;
        QSqlQuery query2;
        query2.exec(str2);
        int temp_num;
        QString temp_addr;
        QString temp_artist = name;
        QString temp_name;
        QString temp_time;
        int temp_hot;
        query2.next();
        //qDebug()<<"aaaa";
        temp_num  = query2.value(0).toInt();
        temp_addr = query2.value(1).toString();
        temp_name = query2.value(3).toString();
        temp_time = query2.value(4).toString();
        temp_hot =  query2.value(5).toInt();
        //qDebug()<<"bbbb";
        pic_info* Info = new pic_info();
        Info->Set_pic_info(temp_num,temp_addr,temp_artist,temp_name,temp_time,temp_hot);
        pictures.append(Info);
    }
    Show_pics();
    //qDebug()<<"pic_base" + QString::number(pic_base) + "like_num" + QString::number(like_num);

}

user_page::~user_page()
{
    delete ui;
}

void user_page::Show_pics()
{
    if((pic_base > like_num) || (pic_base < 0)){
        ui->time1->hide();
        ui->hot1->hide();
        ui->name1->hide();
        ui->watch1->hide();
        ui->time2->hide();
        ui->hot2->hide();
        ui->name2->hide();
        ui->watch2->hide();
        ui->time3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        ui->watch3->hide();
        return;
    }
    //qDebug()<<"aaa";
    QSize laSize1=ui->pic1->size();
    QImage image1;
    image1.load(pictures.at(pic_base-1)->addr);
    image1 = image1.scaled(laSize1,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    //qDebug()<<"bbb";
    ui->pic1->setPixmap(QPixmap::fromImage(image1));
    ui->name1->setText(pictures.at(pic_base-1)->name);
    ui->time1->setText(pictures.at(pic_base-1)->time);
    ui->hot1->setText(QString::number(pictures.at(pic_base-1)->hot));
    //qDebug()<<"ccc";
    if(pic_base+1 > like_num){
        ui->time2->hide();
        ui->hot2->hide();
        ui->name2->hide();
        ui->watch2->hide();
        ui->time3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        ui->watch3->hide();
        return;
    }
    QSize laSize2=ui->pic2->size();
    QImage image2;
    image2.load(pictures.at(pic_base)->addr);
    image2 = image2.scaled(laSize2,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic2->setPixmap(QPixmap::fromImage(image2));
    ui->name2->setText(pictures.at(pic_base)->name);
    ui->time2->setText(pictures.at(pic_base)->time);
    ui->hot2->setText(QString::number(pictures.at(pic_base)->hot));

    if(pic_base+2 > like_num){
        ui->time3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        ui->watch3->hide();
        return;
    }
    QSize laSize3=ui->pic2->size();
    QImage image3;
    image3.load(pictures.at(pic_base+1)->addr);
    image3 = image3.scaled(laSize3,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic3->setPixmap(QPixmap::fromImage(image3));
    ui->name3->setText(pictures.at(pic_base+1)->name);
    ui->time3->setText(pictures.at(pic_base+1)->time);
    ui->hot3->setText(QString::number(pictures.at(pic_base+1)->hot));

    if(pic_base+ 6 > like_num){
        ui->next_pic_2->setEnabled(false);
    }
}

void user_page::on_next_pic_clicked()
{
    if(pic_base + 3 <= like_num){
        pic_base = pic_base + 1;
    }
    Show_pics();
    ui->pre_pic->setEnabled(true);
    if(pic_base >= 4){
        ui->pre_pic_2->setEnabled(true);
    }
}

void user_page::on_pre_pic_clicked()
{
    if(pic_base>1){
        pic_base = pic_base - 1;
    }
    Show_pics();
    ui->next_pic->setEnabled(true);
    if(pic_base+ 5 <= like_num){
        ui->next_pic_2->setEnabled(true);
    }
}

void user_page::on_watch1_clicked()
{
    big_picture = new big_pic(pictures.at(pic_base-1)->num , user_num);
    big_picture->setWindowModality(Qt::ApplicationModal);
    big_picture->show();
}

void user_page::on_watch2_clicked()
{
    big_picture = new big_pic(pictures.at(pic_base)->num , user_num);
    big_picture->setWindowModality(Qt::ApplicationModal);
    big_picture->show();
}

void user_page::on_watch3_clicked()
{
    big_picture = new big_pic(pictures.at(pic_base+1)->num , user_num);
    big_picture->setWindowModality(Qt::ApplicationModal);
    big_picture->show();
}
