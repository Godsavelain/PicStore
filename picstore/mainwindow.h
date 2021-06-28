#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileDialog>
#include <QList>
#include <QString>
#include <QDateTime>
#include <QVector>

#include <QDebug>

#include "pic_show.h"
#include "login.h"
#include "regist.h"
#include "big_pic.h"
#include "user_page.h"
#include "manage_page.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connection();
    void putwidget(QWidget* widget);
    void Cal_pages();
    QSqlDatabase db;
    Pic_Show *pic_show_widget;
    Login *login;
    regist *user_register;
    big_pic *big_picture;
    user_page *user_page_show;
    manage_page *manage_page_show;
    int mode=0;
    int base=1;
    int total_num=0;
    int user;
    int user_type;//0 for normal 1 for artist 2 for admin
    QVector<int> base_vec;
    int current_page=0;
    int page_num=0;
    int total_pic_num;
    QString user_name;

private slots:
    void on_nextpage_clicked();

    void on_pre_page_clicked();

    void on_first_page_clicked();

    void on_last_page_clicked();

    void Call_Register();

    void Login_Success(int user);

    void AddUser(QString , QString ,int);

    void on_pushButton_clicked();

    void on_user_info_clicked();

    void Show_big_pic(int);

    void flush();

    void on_upload_clicked();

    void on_manage_clicked();

    void on_flush_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
