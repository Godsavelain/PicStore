#include "manage_page.h"
#include "ui_manage_page.h"


manage_page::manage_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage_page)
{
    ui->setupUi(this);
    check = new check_page();
    change_page = new change_info();
    ui->centralwidget->addWidget(check);
}

manage_page::~manage_page()
{
    delete ui;
}

void manage_page::on_change_mode_clicked()
{
    if(mode == 0){
        mode = 1;
        ui->change_mode->setText("修改模式");
        delete check;
        change_page = new change_info();
        ui->centralwidget->addWidget(change_page);
    }
    else{
        mode = 0;
        ui->change_mode->setText("审核模式");
        delete change_page;
        check = new check_page();
        ui->centralwidget->addWidget(check);
    }
}
