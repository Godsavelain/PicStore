#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    QString name = ui->usernamein->toPlainText();
    QString psd = ui->passwordin->toPlainText();
    if(name == ""){
        QMessageBox::warning(this,"错误","未输入用户名！");
        return;
    }
    QString str = QString("SELECT * FROM ac WHERE id = %1 ").arg(name);//查询操作
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    if(query.next()){
    QString true_psw = query.value(2).toString();
    //qDebug()<<true_psw;
    if(true_psw == psd){
        QMessageBox::warning(this,"已登录","登陆成功！");
        int user = name.toInt();
        emit login_success_sig(user);
    }
    else{
        QMessageBox::warning(this,"错误","密码错误！");
    }
    }
    else{
        QMessageBox::warning(this,"错误","此账号不存在！");
    }

}

void Login::on_register_2_clicked()
{
        emit call_register_sig();
        qDebug()<<"login call register";
}
