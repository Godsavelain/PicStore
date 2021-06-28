#ifndef PIC_SHOW_H
#define PIC_SHOW_H

#include <QWidget>
#include <QVector>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QImage>
#include <QSize>

#include <QDebug>
#include "pic_info.h"
#include "big_pic.h"
#include "artist_page.h"

namespace Ui {
class Pic_Show;
}

class Pic_Show :public QWidget
{
    Q_OBJECT

public:
    explicit Pic_Show(QWidget *parent = 0);
    Pic_Show(int basein, int modein, QWidget *parent = 0);
    Get_pics();
    Show_pics();
    Show_pic1();
    Show_pic2();
    Show_pic3();
    Show_pic4();
    Show_pic5();
    Show_pic6();

    Show_big_pic(int number);

    big_pic *big_picture;

    int total_pic_num;
    int base_num;
    int last_num;
    int page=0;

    QVector<pic_info*> pictures;
    int mode=0;//0 for normal ,1 for reverse,2 for hot
    ~Pic_Show();

private slots:
    void on_show1_clicked();

    void on_show2_clicked();

    void on_show3_clicked();

    void on_show4_clicked();

    void on_show5_clicked();

    void on_show6_clicked();

signals:
    void Show_big_pic_sig(int);
    void Tell_new_base(int);

private:
       Ui::Pic_Show *ui;

};

#endif // PIC_SHOW_H
