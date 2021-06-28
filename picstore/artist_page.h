#ifndef ARTIST_PAGE_H
#define ARTIST_PAGE_H

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

namespace Ui {
class artist_page;
}

class artist_page : public QWidget
{
    Q_OBJECT

public:
    artist_page(QWidget *parent = 0);
    artist_page(int num, int user_num, QWidget *parent = 0);
    ~artist_page();
    QVector<pic_info*> pictures;
    void Showpics();
    int base = 0;
    int number;
    int hot;
    int artist_num;
    int user_num;

private slots:
    void on_pre_pic_clicked();

    void on_next_pic_clicked();

    void on_pushButton_clicked();


private:
    Ui::artist_page *ui;

signals:
    void Like_artist_sig(int);
};

#endif // ARTIST_PAGE_H
