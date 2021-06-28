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
    ui->show1->setText("点击查看");
    ui->show2->setText("点击查看");
    ui->show3->setText("点击查看");
    ui->show4->setText("点击查看");
    ui->show5->setText("点击查看");
    ui->show6->setText("点击查看");

    QString str = QString("SELECT COUNT(1) FROM p");//查询操作
    QSqlQuery query;
    query.exec(str);
    query.next();
    total_pic_num = query.value(0).toInt();
    qDebug()<<"total_pic_num" + QString::number(total_pic_num);
    qDebug()<<"base:" + QString::number(base_num);
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
    QString str = QString("SELECT COUNT(1) FROM p");//查询操作
    QSqlQuery query;
    query.exec(str);
    query.next();
    total_pic_num = query.value(0).toInt();
    Get_pics();
    Show_pics();
}

Pic_Show::Get_pics(){
    int i=0;
    int base = base_num;
    //qDebug()<<"base1:" + QString::number(base);
    switch (mode) {
    case 0:
        while((i<6) && (pictures.length()<total_pic_num-base_num+2)){
            QString str = QString("SELECT * FROM P WHERE num = %1 ").arg(base);//查询操作
            //qDebug()<<str;
            QSqlQuery query;
            query.exec(str);
            if(!query.next()){
                base++;
                continue;
            }
            else{
                i++;
                last_num = base;
            }
            int temp_num = base;
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
            base++;
        }
        break;
    default:
        break;
    }
}

Pic_Show::Show_pics(){
    int number = pictures.length();
    //qDebug()<<"number:" + QString::number(number);
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
        ui->show2->hide();
        ui->artist3->hide();
        ui->time3->hide();
        ui->pic3->hide();
        ui->hot3->hide();
        ui->name3->hide();
        ui->show3->hide();
        ui->artist4->hide();
        ui->time4->hide();
        ui->pic4->hide();
        ui->hot4->hide();
        ui->name4->hide();
        ui->show4->hide();
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->show5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
        ui->show6->hide();
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
        ui->show3->hide();
        ui->artist4->hide();
        ui->time4->hide();
        ui->pic4->hide();
        ui->hot4->hide();
        ui->name4->hide();
        ui->show4->hide();
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->show5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
        ui->show6->hide();
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
        ui->show4->hide();
        ui->artist5->hide();
        ui->time5->hide();
        ui->pic5->hide();
        ui->hot5->hide();
        ui->name5->hide();
        ui->show5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
        ui->show6->hide();
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
        ui->show5->hide();
        ui->artist6->hide();
        ui->time6->hide();
        ui->pic6->hide();
        ui->hot6->hide();
        ui->name6->hide();
        ui->show6->hide();
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
        ui->show6->hide();
    }
    //qDebug()<<number;
}

Pic_Show::Show_pic1(){
    //qDebug()<<"Show_pic_1";
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

    //qDebug()<<"addr:"+temp_addr;
    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic1->setPixmap(QPixmap::fromImage(image));

    ui->artist1->setText(temp_artist);
    ui->name1->setText(temp_name);
    ui->time1->setText(temp_time);
    ui->hot1->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic2(){
    //qDebug()<<"Show_pic_2";
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

    //qDebug()<<"addr:"+temp_addr;

    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic2->setPixmap(QPixmap::fromImage(image));

    ui->artist2->setText(temp_artist);
    ui->name2->setText(temp_name);
    ui->time2->setText(temp_time);
    ui->hot2->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic3(){
    //qDebug()<<"Show_pic_3";
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

    //qDebug()<<"addr:"+temp_addr;
    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic3->setPixmap(QPixmap::fromImage(image));

    ui->artist3->setText(temp_artist);
    ui->name3->setText(temp_name);
    ui->time3->setText(temp_time);
    ui->hot3->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic4(){
    //qDebug()<<"Show_pic_4";
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

    //qDebug()<<"addr:"+temp_addr;
    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic4->setPixmap(QPixmap::fromImage(image));

    ui->artist4->setText(temp_artist);
    ui->name4->setText(temp_name);
    ui->time4->setText(temp_time);
    ui->hot4->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic5(){
    //qDebug()<<"Show_pic_5";
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

    //qDebug()<<"addr:"+temp_addr;
    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic5->setPixmap(QPixmap::fromImage(image));

    ui->artist5->setText(temp_artist);
    ui->name5->setText(temp_name);
    ui->time5->setText(temp_time);
    ui->hot5->setText(QString::number(temp_hot));
}

Pic_Show::Show_pic6(){
    //qDebug()<<"Show_pic_6";
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

    //qDebug()<<"addr:"+temp_addr;
    image.load(temp_addr);
    image = image.scaled(laSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->pic6->setPixmap(QPixmap::fromImage(image));

    ui->artist6->setText(temp_artist);
    ui->name6->setText(temp_name);
    ui->time6->setText(temp_time);
    ui->hot6->setText(QString::number(temp_hot));
}

Pic_Show::Show_big_pic(int number)
{
    qDebug()<<"Show_big_pic_sig";
    switch (number) {
    case 1:
        emit Show_big_pic_sig(pictures.at(0)->num);
//        big_picture = new big_pic(pictures.at(0)->num);
//        big_picture->show();
        break;
    case 2:
        emit Show_big_pic_sig(pictures.at(1)->num);
//        big_picture = new big_pic(pictures.at(1)->num);
//        big_picture->show();
        break;
    case 3:
        emit Show_big_pic_sig(pictures.at(2)->num);
//        big_picture = new big_pic(pictures.at(2)->num);
//        big_picture->show();
        break;
    case 4:
        emit Show_big_pic_sig(pictures.at(3)->num);
//        big_picture = new big_pic(pictures.at(3)->num);
//        big_picture->show();
        break;
    case 5:
        emit Show_big_pic_sig(pictures.at(4)->num);
//        big_picture = new big_pic(pictures.at(4)->num);
//        big_picture->show();
        break;
    case 6:
        emit Show_big_pic_sig(pictures.at(5)->num);
//        big_picture = new big_pic(pictures.at(5)->num);
//        big_picture->show();
        break;
    default:
        break;
    }
}

Pic_Show::~Pic_Show(){
    delete ui;
}

void Pic_Show::on_show1_clicked()
{
    Show_big_pic(1);
}

void Pic_Show::on_show2_clicked()
{
    Show_big_pic(2);
}

void Pic_Show::on_show3_clicked()
{
    Show_big_pic(3);
}

void Pic_Show::on_show4_clicked()
{
    Show_big_pic(4);
}

void Pic_Show::on_show5_clicked()
{
    Show_big_pic(5);
}

void Pic_Show::on_show6_clicked()
{
    Show_big_pic(6);
}
