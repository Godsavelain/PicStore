#include "big_pic.h"
#include "ui_big_pic.h"


big_pic::big_pic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::big_pic)
{
    ui->setupUi(this);
}

big_pic::big_pic(int num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::big_pic)
{
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
    //qDebug()<<str;

    query.exec(str);
    if(query.next()){
        artist_num = query.value(0).toInt();
    }

}

big_pic::~big_pic()
{
    delete ui;
}


void big_pic::on_pushButton_clicked()
{
    art_page = new artist_page(artist_num);
    art_page->show();
}
