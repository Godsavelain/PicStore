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

#include "pic_info.h"

namespace Ui {
class artist_page;
}

class artist_page : public QWidget
{
    Q_OBJECT

public:
    artist_page(QWidget *parent = 0);
    artist_page(int num, QWidget *parent = 0);
    ~artist_page();
    QVector<pic_info*> pictures;
    void Showpics();
    int base = 0;
    int number;
    int hot;

private slots:
    void on_pre_pic_clicked();

    void on_next_pic_clicked();

private:
    Ui::artist_page *ui;
};

#endif // ARTIST_PAGE_H
