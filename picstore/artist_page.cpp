#include "artist_page.h"
#include "ui_artist_page.h"

artist_page::artist_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::artist_page)
{
    ui->setupUi(this);
}

artist_page::artist_page(int num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::artist_page)
{
    ui->setupUi(this);
    QString str = QString("SELECT * FROM a WHERE num = %1 ").arg(num);//查询操作
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    if(!query.next()){
        return;
    }
    QString name;

    name = query.value(1).toString();
    number = query.value(2).toInt();
    hot = query.value(3).toInt();

    ui->name->setText(name);
    ui->number->setText(QString::number(number));
    ui->hot->setText(QString::number(hot));

    str = QString("SELECT * FROM p WHERE artist ='%1' ").arg(name);
    query.exec(str);
    while(query.next()){
        int temp_num;
        QString temp_addr;
        QString temp_artist = name;
        QString temp_name;
        QString temp_time;
        int temp_hot;
        temp_num  = query.value(0).toInt();
        temp_addr = query.value(1).toString();
        temp_name = query.value(3).toString();
        temp_time = query.value(4).toString();
        temp_hot =  query.value(5).toInt();
        pic_info* Info = new pic_info();
        Info->Set_pic_info(temp_num,temp_addr,temp_artist,temp_name,temp_time,temp_hot);
        pictures.append(Info);
    }
    Showpics();
}

artist_page::~artist_page()
{
    delete ui;
}

void artist_page::Showpics()
{
    if(base > number){
        ui->time1->hide();
        ui->hot1->hide();
        ui->name1->hide();
        ui->time2->hide();
        ui->hot2->hide();
        ui->name2->hide();
        ui->time3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        return;
    }
    QSize laSize1=ui->pic1->size();
    QImage image1;
    image1.load(pictures.at(base)->addr);
    image1 = image1.scaled(laSize1,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic1->setPixmap(QPixmap::fromImage(image1));
    ui->name1->setText(pictures.at(base)->name);
    ui->time1->setText(pictures.at(base)->time);
    ui->hot1->setText(QString::number(pictures.at(base)->hot));

    if(base+1 > number){
        ui->time2->hide();
        ui->hot2->hide();
        ui->name2->hide();
        ui->time3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        return;
    }
    QSize laSize2=ui->pic2->size();
    QImage image2;
    image2.load(pictures.at(base+1)->addr);
    image2 = image2.scaled(laSize2,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic2->setPixmap(QPixmap::fromImage(image2));
    ui->name2->setText(pictures.at(base+1)->name);
    ui->time2->setText(pictures.at(base+1)->time);
    ui->hot2->setText(QString::number(pictures.at(base+1)->hot));

    if(base+2 > number){
        ui->time3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        return;
    }
    QSize laSize3=ui->pic2->size();
    QImage image3;
    image3.load(pictures.at(base+2)->addr);
    image3 = image3.scaled(laSize3,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic3->setPixmap(QPixmap::fromImage(image3));
    ui->name3->setText(pictures.at(base+2)->name);
    ui->time3->setText(pictures.at(base+2)->time);
    ui->hot3->setText(QString::number(pictures.at(base+2)->hot));
}

void artist_page::on_pre_pic_clicked()
{
    base = base-1;
    Showpics();
}

void artist_page::on_next_pic_clicked()
{
    base = base+1;
    Showpics();
}
