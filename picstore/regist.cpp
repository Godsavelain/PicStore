#include "regist.h"
#include "ui_regist.h"

regist::regist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
}

regist::~regist()
{
    delete ui;
}

void regist::on_pushButton_clicked()
{
    QString name;
    QString password;
    int mode=0;
    name = ui->usernamein->toPlainText();
    password = ui->passwordin->toPlainText();
    if(ui->checkBox->isChecked()){
        mode=1;
    }
    emit register_sig(name,password,mode);
}
