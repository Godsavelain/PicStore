#ifndef BIG_PIC_H
#define BIG_PIC_H

#include <QWidget>
#include <QVector>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QImage>
#include <QSize>
#include <QDebug>

#include "artist_page.h"

namespace Ui {
class big_pic;
}

class big_pic : public QWidget
{
    Q_OBJECT

public:
    big_pic(QWidget *parent = 0);
    big_pic(int num, QWidget *parent = 0);
    ~big_pic();
    artist_page *art_page;
    int artist_num;


private slots:
    void on_pushButton_clicked();

private:
    Ui::big_pic *ui;
};

#endif // BIG_PIC_H
