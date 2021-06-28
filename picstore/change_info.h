#ifndef CHANGE_INFO_H
#define CHANGE_INFO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>

namespace Ui {
class change_info;
}

class change_info : public QWidget
{
    Q_OBJECT

public:
    explicit change_info(QWidget *parent = 0);
    ~change_info();

private slots:
    void on_change_clicked();

    void on_del_clicked();

private:
    Ui::change_info *ui;
};

#endif // CHANGE_INFO_H
