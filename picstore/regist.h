#ifndef REGIST_H
#define REGIST_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QString>


namespace Ui {
class regist;
}

class regist : public QWidget
{
    Q_OBJECT

public:
    explicit regist(QWidget *parent = 0);
    ~regist();

private:
    Ui::regist *ui;

signals:
    void register_sig(QString, QString ,int);

private slots:
    void on_pushButton_clicked();
};

#endif // REGIST_H
