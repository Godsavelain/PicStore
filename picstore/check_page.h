#ifndef CHECK_PAGE_H
#define CHECK_PAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QImage>
#include <QSize>
#include <QDebug>

#include "pic_info.h"

namespace Ui {
class check_page;
}

class check_page : public QWidget
{
    Q_OBJECT

public:
    explicit check_page(QWidget *parent = 0);
    Get_pics();
    ~check_page();
    pic_info* picture;

private slots:
    void on_pass_clicked();

private:
    Ui::check_page *ui;
};

#endif // CHECK_PAGE_H
