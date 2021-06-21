#ifndef PIC_SHOW_H
#define PIC_SHOW_H

#include <QWidget>
#include <QVector>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QImage>
#include <QSize>

#include <QDebug>
#include "pic_info.h"

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
    QVector<pic_info*> pictures;
    int mode=0;//0 for normal ,1 for reverse,2 for hot
    ~Pic_Show();

private:
       Ui::Pic_Show *ui;
       int base_num;
};

#endif // PIC_SHOW_H
