#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>

#include "pic_show.h"
#include "login.h"
#include "regist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connect();
    void putwidget(QWidget* widget);
    QSqlDatabase db;
    Pic_Show *pic_show_widget;
    Login *login;
    regist *user_register;
    int mode=0;
    int base=1;
    int total_num=0;

private slots:
    void on_nextpage_clicked();

    void on_pre_page_clicked();

    void on_first_page_clicked();

    void on_last_page_clicked();

    void Call_Register();

    void Login_Success();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
