#include "big_pic.h"
#include "ui_big_pic.h"


big_pic::big_pic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::big_pic)
{
    ui->setupUi(this);
}

big_pic::big_pic(int num,int user_nember,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::big_pic)
{
    pic_num = num;
    user_num = user_nember;
    ui->setupUi(this);
    QString str = QString("SELECT * FROM P WHERE num = %1 ").arg(num);//查询操作
    qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    if(!query.next()){
        return;
    }
    QString addr;
    QString name;
    QString artist;
    QString time;
    int hot;
    addr = query.value(1).toString();
    name = query.value(3).toString();
    artist = query.value(2).toString();
    time = query.value(4).toString();
    hot = query.value(5).toInt();
    QSize laSize=ui->picture->size();
    QImage image;
    image.load(addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->picture->setPixmap(QPixmap::fromImage(image));

    ui->name->setText(name);
    ui->artist->setText(artist);
    ui->time->setText(time);
    ui->hot->setText(QString::number(hot));

    str = QString("SELECT * FROM a WHERE name = '%1' ").arg(artist);//查询操作
    //qDebug()<<"aaa";

    query.exec(str);
    if(query.next()){
        artist_num = query.value(0).toInt();
    }

    str = QString("SELECT * FROM ul WHERE unum = '%1' AND pnum = '%2' ").arg(user_num).arg(pic_num);
    query.exec(str);
    if(query.next()){
        ui->like->setEnabled(false);
    }


}

big_pic::~big_pic()
{
    delete ui;
}


void big_pic::on_pushButton_clicked()
{
    art_page = new artist_page(artist_num , user_num);
    art_page->setWindowModality(Qt::ApplicationModal);
    art_page->show();
    connect(art_page,SIGNAL(Like_artist_sig(int)),this,SLOT(Like_artist(int)));
}

void big_pic::on_like_clicked()//收藏
{
    ui->hot->setText(QString::number(ui->hot->text().toInt()+1));
    QSqlQuery query;
    QString str = QString("UPDATE p SET hot = %1 WHERE num = %2 ").\
            arg(QString::number(ui->hot->text().toInt())).arg(pic_num);//修改操作
    qDebug()<<str;
    query.exec(str);
    str = QString("insert into ul(unum,pnum) values(%1 , %2 )").\
            arg(user_num).arg(pic_num);
    qDebug()<<str;
    query.exec(str);

    ui->like->setEnabled(false);
}

void big_pic::Like_artist(int artist_id)
{
    QString str = QString("insert into ua(usdrid,artistid) values(%1 , %2 )").\
            arg(user_num).arg(artist_id);//查询操作
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
}
