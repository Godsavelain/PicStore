#include "pic_show.h"
#include "ui_pic_show.h"

Pic_Show::Pic_Show(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Pic_Show)
{
    ui->setupUi(this);
    base_num = 1;
    Get_pics();
    Show_pics();
}

Pic_Show::Pic_Show(int basein,int modein, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Pic_Show)
{
    ui->setupUi(this);
    base_num = basein;
    mode = modein;
    Get_pics();
    Show_pics();
}

Pic_Show::Get_pics(){
    switch (mode) {
    case 0:
        for(int i=base_num;i<base_num+6;i++){
            QString str = QString("SELECT * FROM P WHERE num = %1 ").arg(i);//查询操作
            //qDebug()<<str;
            QSqlQuery query;
            query.exec(str);
            if(!query.next()){
                break;
            }
            int temp_num = i;
            QString temp_addr;
            QString temp_artist;
            QString temp_name;
            QString temp_time;
            int temp_hot;
            temp_addr = query.value(1).toString();
            temp_artist = query.value(2).toString();
            temp_name = query.value(3).toString();
            temp_time = query.value(4).toString();
            temp_hot =  query.value(5).toInt();
            pic_info* Info = new pic_info();
            Info->Set_pic_info(temp_num,temp_addr,temp_artist,temp_name,temp_time,temp_hot);
            pictures.append(Info);
            //qDebug()<<temp_addr + "a" + temp_artist + "a" + temp_name + " " + temp_time;
        }
        break;
    default:
        break;
    }
}

Pic_Show::Show_pics(){
    int number = pictures.length();
    if(number>0){
        Show_pic1();
    }
    if(number>1){
        Show_pic2();
    }
    else{
        ui->artist2->hide();
        ui->time2->hide();
        ui->pic2->hide();
        ui->hot2->hide();
        ui->name2->hide();
        ui->artist3->hide();
        ui->time3->hide();
        ui->pic3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        ui->artist4->hide();
        ui->time4->hide();
        ui->pic4->hide();
        ui->hot4->hide();
        ui->name4->hide();
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
    }
    if(number>2){
        Show_pic3();
    }
    else{
        ui->artist3->hide();
        ui->time3->hide();
        ui->pic3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        ui->artist4->hide();
        ui->time4->hide();
        ui->pic4->hide();
        ui->hot4->hide();
        ui->name4->hide();
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
    }
    if(number>3){
        Show_pic4();
    }
    else{
        ui->artist4->hide();
        ui->time4->hide();
        ui->pic4->hide();
        ui->hot4->hide();
        ui->name4->hide();
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
    }
    if(number>4){
        Show_pic5();
    }
    else{
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
    }
    if(number>5){
        Show_pic6();
    }
    else {
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
    }
    //qDebug()<<number;
}

Pic_Show::Show_pic1(){
    QString temp_addr;
    QString temp_artist;
    QString temp_name;
    QString temp_time;
    int temp_hot;
    temp_addr = pictures.at(0)->addr;
    temp_artist = pictures.at(0)->artist;
    temp_name = pictures.at(0)->name;
    temp_time = pictures.at(0)->time;
    temp_hot = pictures.at(0)->hot;
    QSize laSize=ui->pic1->size();
    QImage image;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic1->setPixmap(QPixmap::fromImage(image));

    ui->artist1->setText(temp_artist);
    ui->name1->setText(temp_name);
    ui->time1->setText(temp_time);
    ui->hot1->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic2(){
    QString temp_addr;
    QString temp_artist;
    QString temp_name;
    QString temp_time;
    int temp_hot;
    temp_addr = pictures.at(1)->addr;
    temp_artist = pictures.at(1)->artist;
    temp_name = pictures.at(1)->name;
    temp_time = pictures.at(1)->time;
    temp_hot = pictures.at(1)->hot;
    QSize laSize=ui->pic2->size();
    QImage image;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic2->setPixmap(QPixmap::fromImage(image));

    ui->artist2->setText(temp_artist);
    ui->name2->setText(temp_name);
    ui->time2->setText(temp_time);
    ui->hot2->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic3(){
    QString temp_addr;
    QString temp_artist;
    QString temp_name;
    QString temp_time;
    int temp_hot;
    temp_addr = pictures.at(2)->addr;
    temp_artist = pictures.at(2)->artist;
    temp_name = pictures.at(2)->name;
    temp_time = pictures.at(2)->time;
    temp_hot = pictures.at(2)->hot;
    QSize laSize=ui->pic3->size();
    QImage image;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic3->setPixmap(QPixmap::fromImage(image));

    ui->artist3->setText(temp_artist);
    ui->name3->setText(temp_name);
    ui->time3->setText(temp_time);
    ui->hot3->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic4(){
    QString temp_addr;
    QString temp_artist;
    QString temp_name;
    QString temp_time;
    int temp_hot;
    temp_addr = pictures.at(3)->addr;
    temp_artist = pictures.at(3)->artist;
    temp_name = pictures.at(3)->name;
    temp_time = pictures.at(3)->time;
    temp_hot = pictures.at(3)->hot;
    QSize laSize=ui->pic4->size();
    QImage image;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic4->setPixmap(QPixmap::fromImage(image));

    ui->artist4->setText(temp_artist);
    ui->name4->setText(temp_name);
    ui->time4->setText(temp_time);
    ui->hot4->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic5(){
    QString temp_addr;
    QString temp_artist;
    QString temp_name;
    QString temp_time;
    int temp_hot;
    temp_addr = pictures.at(4)->addr;
    temp_artist = pictures.at(4)->artist;
    temp_name = pictures.at(4)->name;
    temp_time = pictures.at(4)->time;
    temp_hot = pictures.at(4)->hot;
    QSize laSize=ui->pic5->size();
    QImage image;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic5->setPixmap(QPixmap::fromImage(image));

    ui->artist5->setText(temp_artist);
    ui->name5->setText(temp_name);
    ui->time5->setText(temp_time);
    ui->hot5->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic6(){
    QString temp_addr;
    QString temp_artist;
    QString temp_name;
    QString temp_time;
    int temp_hot;
    temp_addr = pictures.at(5)->addr;
    temp_artist = pictures.at(5)->artist;
    temp_name = pictures.at(5)->name;
    temp_time = pictures.at(5)->time;
    temp_hot = pictures.at(5)->hot;
    QSize laSize=ui->pic6->size();
    QImage image;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic6->setPixmap(QPixmap::fromImage(image));

    ui->artist6->setText(temp_artist);
    ui->name6->setText(temp_name);
    ui->time6->setText(temp_time);
    ui->hot6->setText(QString::number(temp_hot));
}

Pic_Show::~Pic_Show(){
    delete ui;
}
