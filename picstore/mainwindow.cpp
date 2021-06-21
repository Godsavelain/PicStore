#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect();
    login = new Login();
    user_register = new regist();
    user_register->hide();
    login->show();

    pic_show_widget = new Pic_Show();
    putwidget(pic_show_widget);
    ui->pre_page->setEnabled(false);
}


void MainWindow::connect(){

    qDebug()<<QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL"); //数据库对象
    db.setHostName("127.0.0.1"); //数据库服务器IP
    db.setUserName("root"); //数据库用户名
    db.setPassword("123456"); //数据库密码
    db.setDatabaseName("pics"); //使用哪个数据库

    if( !db.open() ){ //数据库打开失败
            QMessageBox::warning(this,"错误",db.lastError().text());
            return;
        }
    else{
        qDebug()<<"成功";
    }
    QString str = QString("SELECT COUNT(1) FROM P ");//查询操作
    QSqlQuery query;
    query.exec(str);
    //qDebug()<<"aaa:" + QString::number(query.value(0).toInt());
    if(query.next()){
        total_num = query.value(0).toInt();
    }
    //qDebug()<<"num:" + QString::number(total_num);
}

 void MainWindow::putwidget(QWidget* widget)
 {
     ui->pHBoxLayout->addWidget(widget);
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextpage_clicked()
{
    switch (mode) {
    case 0:
        base = base + 6;
        if((base+6) > total_num ){
            ui->nextpage->setEnabled(false);
            //qDebug()<<"base:" + QString::number(base) + "total:" + QString::number(total_num);
        }
            ui->pre_page->setEnabled(true);
        delete pic_show_widget;
        pic_show_widget = new Pic_Show(base,0);
        putwidget(pic_show_widget);
        break;
    default:
        break;
    }
}

void MainWindow::on_pre_page_clicked()
{
    switch (mode) {
    case 0:
        base = base - 6;
        if((base-6) < 0 ){
            ui->pre_page->setEnabled(false);
            //qDebug()<<"base:" + QString::number(base) + "total:" + QString::number(total_num);
        }
        ui->nextpage->setEnabled(true);
        delete pic_show_widget;
        pic_show_widget = new Pic_Show(base,0);
        putwidget(pic_show_widget);
        break;
    default:
        break;
    }
}

void MainWindow::on_first_page_clicked()
{

}

void MainWindow::on_last_page_clicked()
{

}

void MainWindow::Call_Register()
{

}

void MainWindow::Login_Success()
{

}
