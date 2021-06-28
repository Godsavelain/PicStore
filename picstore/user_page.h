#ifndef USER_PAGE_H
#define USER_PAGE_H

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

namespace Ui {
class user_page;
}

class user_page : public QWidget
{
    Q_OBJECT

public:
    user_page(QWidget *parent = 0);
    user_page(int, QWidget *parent = 0);
    ~user_page();
    big_pic *big_picture;
    int user_num;
    int pic_base=1;
    int like_num;
    QVector<pic_info*> pictures;
    void Show_pics();

private slots:
    void on_next_pic_clicked();

    void on_pre_pic_clicked();

    void on_watch1_clicked();

    void on_watch2_clicked();

    void on_watch3_clicked();

private:
    Ui::user_page *ui;
};

#endif // USER_PAGE_H
