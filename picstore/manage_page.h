#ifndef MANAGE_PAGE_H
#define MANAGE_PAGE_H

#include "change_info.h"
#include "check_page.h"

#include <QWidget>

namespace Ui {
class manage_page;
}

class manage_page : public QWidget
{
    Q_OBJECT

public:
    explicit manage_page(QWidget *parent = 0);
    ~manage_page();
    change_info *change_page;
    check_page *check;
    int mode = 0;
    int total_num=0;

private slots:
    void on_change_mode_clicked();

private:
    Ui::manage_page *ui;
};

#endif // MANAGE_PAGE_H
