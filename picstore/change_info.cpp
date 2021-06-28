#include "change_info.h"
#include "ui_change_info.h"

change_info::change_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_info)
{
    ui->setupUi(this);
}

change_info::~change_info()
{
    delete ui;
}

void change_info::on_change_clicked()
{
    int num = ui->id_input->toPlainText().toInt();
    QString str = QString("SELECT * FROM p WHERE num = %1 ").arg(num);//查询操作
    QSqlQuery query;
    query.exec(str);
    if(!query.next()){
        QMessageBox::warning(this,"错误","此图片不存在");
        return;
    }
    else{
        if(ui->namebox->isChecked()){
            QString new_name;
            if(ui->name_in->toPlainText() == ""){
                QMessageBox::warning(this,"错误","未输入图片名");
                return;
            }
            new_name = ui->name_in->toPlainText();
            str = QString("UPDATE p SET name = '%1' WHERE num = %2 ").arg(new_name).arg(num);//查询操作
            query.exec(str);
        }
        if(ui->artistbox->isChecked()){
            QString artist_num;
            if(ui->artist_in->toPlainText() == ""){
                QMessageBox::warning(this,"错误","未输入作者ID");
                return;
            }
            artist_num = ui->artist_in->toPlainText();
            str = QString("SELECT * FROM a WHERE num = %1 ").arg(artist_num.toInt());
            query.exec(str);
            if(!query.next()){
                QMessageBox::warning(this,"错误","该作者不存在！");
                return;
            }
            QString artist_name = query.value(1).toString();
            str = QString("UPDATE p SET artist = '%1' WHERE num = %2").arg(artist_name).arg(num);//查询操作
            query.exec(str);
        }
        if(ui->timebox->isChecked()){
            QString new_time;
            if(ui->time_in->toPlainText() == ""){
                QMessageBox::warning(this,"错误","未输入新的时间");
                return;
            }
            new_time = ui->time_in->toPlainText();
            str = QString("UPDATE p SET time = '%1' WHERE num = %2").arg(new_time).arg(num);//查询操作
            query.exec(str);
        }
        if(ui->hotbox->isChecked()){
            QString new_hot;
            if(ui->hot_in->toPlainText() == ""){
                QMessageBox::warning(this,"错误","未输入新的热度");
                return;
            }
            new_hot = ui->hot_in->toPlainText();
            str = QString("UPDATE p SET hot = %1 WHERE num = %2").arg(new_hot.toInt()).arg(num);//查询操作
            query.exec(str);
        }
    }
    QMessageBox::warning(this,"成功","已修改");

}

void change_info::on_del_clicked()
{
    int num = ui->id_input->toPlainText().toInt();
    QString str = QString("SELECT * FROM p WHERE num = %1 ").arg(num);//查询操作
    QSqlQuery query;
    query.exec(str);
    if(!query.next()){
        QMessageBox::warning(this,"错误","此图片不存在");
        return;
    }
    else{
        QString artist_name;
        str = QString("SELECT * FROM p WHERE num = %1 ").arg(num);
        qDebug()<<str;
        query.exec(str);
        query.next();
        artist_name = query.value(2).toString();
        qDebug()<<artist_name;
        int old_number;
        int artit_id;
        str = QString("SELECT * FROM a WHERE name = '%1' ").arg(artist_name);
        qDebug()<<str;
        query.exec(str);
        query.next();
        old_number = query.value(2).toInt();
        artit_id = query.value(0).toInt();
        qDebug()<<"old_number:"+QString::number(old_number);
        qDebug()<<"artit_id:"+QString::number(artit_id);
        str = QString("UPDATE a SET number = %1 WHERE name = '%2'").arg(old_number-1).arg(artist_name);
        qDebug()<<str;
        query.exec(str);


        str = QString("DELETE FROM pt WHERE pnum = %1").arg(num);
        qDebug()<<str;
        query.exec(str);

        str = QString("DELETE FROM ul WHERE pnum = %1").arg(num);
        qDebug()<<str;
        query.exec(str);

        str = QString("DELETE FROM p WHERE num = %1").arg(num);
        qDebug()<<str;
        query.exec(str);

        QMessageBox::warning(this,"成功","删除完成");
    }
}
