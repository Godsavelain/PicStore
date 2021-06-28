#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connection();
    login = new Login();
    user_register = new regist();
    pic_show_widget = new Pic_Show(base,0);
    connect(login,SIGNAL(login_success_sig(int)),this,SLOT(Login_Success(int)));
    connect(login,SIGNAL(call_register_sig()),this,SLOT(Call_Register()));
    connect(user_register,SIGNAL(register_sig(QString, QString ,int)),this,SLOT(AddUser(QString , QString ,int)));
    connect(pic_show_widget,SIGNAL(Show_big_pic_sig(int)),this,SLOT(Show_big_pic(int)));
    user_register->hide();
    login->show();

    Cal_pages();
    putwidget(pic_show_widget);
    ui->pre_page->setEnabled(false);
    ui->user_info->setFlat(true);

}


void MainWindow::connection(){
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

 void MainWindow::Cal_pages()
 {
     switch (mode) {
     case 0:
         int num = 0;
         QString str = QString("SELECT COUNT(1) FROM p");//查询操作
         QSqlQuery query;
         query.exec(str);
         query.next();
         total_pic_num = query.value(0).toInt();
         if((total_pic_num % 6) == 0){
             page_num = (total_pic_num/6)-1;
         }
         else{
             page_num = total_pic_num/6;
         }
         int i=0;
         for(i=0;i<=page_num;i++){
             base_vec.append(num);
             int j=0;
             while((j<6)&&(num<total_pic_num)){
                 str = QString("SELECT * FROM P WHERE num = %1").arg(num);//查询操作
                 query.exec(str);
                 if(query.next()){
                     j++;
                 };
                 num++;
             }
         }
         break;

     }
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextpage_clicked()
{
    qDebug()<<"current num"+ QString::number(base);
    switch (mode) {
    case 0:
        current_page++;
        if(current_page==page_num){
            ui->nextpage->setEnabled(false);
            //qDebug()<<"base:" + QString::number(base) + "total:" + QString::number(total_num);
        }
            ui->pre_page->setEnabled(true);
        delete pic_show_widget;
        pic_show_widget = new Pic_Show(base_vec.at(current_page),0);
        putwidget(pic_show_widget);
        break;
    default:
        break;
    }
    connect(login,SIGNAL(login_success_sig(int)),this,SLOT(Login_Success(int)));
    connect(login,SIGNAL(call_register_sig()),this,SLOT(Call_Register()));
    connect(user_register,SIGNAL(register_sig(QString, QString ,int)),this,SLOT(AddUser(QString , QString ,int)));
    connect(pic_show_widget,SIGNAL(Show_big_pic_sig(int)),this,SLOT(Show_big_pic(int)));
}

void MainWindow::on_pre_page_clicked()
{
    qDebug()<<"current num"+ QString::number(base);
    connect(login,SIGNAL(login_success_sig(int)),this,SLOT(Login_Success(int)));
    connect(login,SIGNAL(call_register_sig()),this,SLOT(Call_Register()));
    connect(user_register,SIGNAL(register_sig(QString, QString ,int)),this,SLOT(AddUser(QString , QString ,int)));
    connect(pic_show_widget,SIGNAL(Show_big_pic_sig(int)),this,SLOT(Show_big_pic(int)));
    switch (mode) {
    case 0:
        current_page--;
        if(current_page == 0 ){
            ui->pre_page->setEnabled(false);
            //qDebug()<<"base:" + QString::number(base) + "total:" + QString::number(total_num);
        }
        ui->nextpage->setEnabled(true);
        delete pic_show_widget;
        pic_show_widget = new Pic_Show(base_vec.at(current_page),0);
        putwidget(pic_show_widget);
        break;
    default:
        break;
    }
    connect(login,SIGNAL(login_success_sig(int)),this,SLOT(Login_Success(int)));
    connect(login,SIGNAL(call_register_sig()),this,SLOT(Call_Register()));
    connect(user_register,SIGNAL(register_sig(QString, QString ,int)),this,SLOT(AddUser(QString , QString ,int)));
    connect(pic_show_widget,SIGNAL(Show_big_pic_sig(int)),this,SLOT(Show_big_pic(int)));
}

void MainWindow::on_first_page_clicked()
{

}

void MainWindow::on_last_page_clicked()
{

}

void MainWindow::Call_Register()
{
    qDebug()<<"register";
    login->hide();
    user_register->show();
}

void MainWindow::Login_Success(int user)
{
    qDebug()<<"log in success!";
    this->show();
    this->user = user;
    this->login->hide();
    QString str = QString("SELECT * FROM ac where id = %1 ").arg(user);//查询操作
    //qDebug()<<str;
    QSqlQuery query;
    query.exec(str);
    //qDebug()<<"aaa:" + QString::number(query.value(0).toInt());
    if(query.next()){
        user_type = query.value(3).toInt();
        user_name = query.value(1).toString();
    }
    ui->user_info->setText(user_name);
    QString type;
    switch (user_type) {
    case 0:
        type = "游客";
        break;
    case 1:
        type = "创作者";
        break;
    case 2:
        type = "管理员";
        break;
    default:
        break;
    }
    ui->user_type->setText(type);
    if(user_type == 0){
        ui->upload->hide();
    }
    if(user_type != 2){
        ui->manage->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::AddUser(QString name, QString password , int mode)
{
    //qDebug()<<"user added";
    QString str = QString("SELECT COUNT(1) FROM AC ");//查询操作
    QSqlQuery query;
    query.exec(str);
    //qDebug()<<"aaa:" + QString::number(query.value(0).toInt());
    int ac_num;
    if(query.next()){
        ac_num = query.value(0).toInt();
    }
    QMessageBox::warning(this,"成功",QString("注册成功，您的id为： %1").arg(ac_num+101));
    str = QString("insert into AC(id ,name ,psw ,type) values(%1 ,'%2' ,'%3' ,%4 )").\
            arg(QString::number(ac_num+101),name,password,QString::number(mode));
    //qDebug()<<str;
    query.exec(str);
    if(mode == 1){
        str = QString("SELECT COUNT(1) FROM a ");//查询操作
        query.exec(str);
        query.next();
        int num = query.value(0).toInt();
        str = QString("insert into A(num,name,number,hot,id) values(%1,'%2',%3,%4,%5)")\
                .arg(QString::number(num+1),name,"0","0",QString::number(ac_num+101));
        query.exec(str);
    }
    user_register->hide();
    login->show();

}

void MainWindow::on_user_info_clicked()
{
    user_page_show = new user_page(user);
    user_page_show->show();
}

void MainWindow::Show_big_pic(int pic_num)
{
    //qDebug()<<"showpics";
    big_picture = new big_pic(pic_num , user);
    big_picture->show();
}

void MainWindow::flush()
{
    Cal_pages();
    current_page=0;
    ui->pre_page->setEnabled(false);
    if(total_pic_num > 6){
        ui->nextpage->setEnabled(true);
    }
    else{
        ui->nextpage->setEnabled(false);
    }
    delete pic_show_widget;
    base = 0;
    pic_show_widget = new Pic_Show(base,mode);
    putwidget(pic_show_widget);
    connect(login,SIGNAL(login_success_sig(int)),this,SLOT(Login_Success(int)));
    connect(login,SIGNAL(call_register_sig()),this,SLOT(Call_Register()));
    connect(user_register,SIGNAL(register_sig(QString, QString ,int)),this,SLOT(AddUser(QString , QString ,int)));
    connect(pic_show_widget,SIGNAL(Show_big_pic_sig(int)),this,SLOT(Show_big_pic(int)));
}



void MainWindow::on_upload_clicked()
{
     QFileDialog fileDlg(this);
     QString fileName;
     QStringList qstrFilters;//设置文件过滤器的list
        qstrFilters<<"Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm)";
        qstrFilters<<"Any files (*)";
        fileDlg.setNameFilters(qstrFilters);//设置文件过滤器
        fileDlg.setFileMode(QFileDialog::ExistingFiles);//设置能选择多个文件，如果是单个文件就写成QFileDialog::ExistingFile
        if(fileDlg.exec() == QDialog::Accepted)
        {
            QStringList strPathList = fileDlg.selectedFiles();//得到用户选择的多个文件的路径的list
            for(int i = 0;i<strPathList.count();i++)
            {
                fileName = strPathList[i];
                int n = fileName.lastIndexOf("/");
                int m = fileName.indexOf(".");
                QString name = fileName.mid(n+1,m-n-1);
                //qDebug()<<name;
                QDateTime current_date_time =QDateTime::currentDateTime();
                QString str = QString("insert into pcheck(num,addr,artist,name,time,hot) values(%1,'%2','%3','%4','%5',%6)")\
                        .arg(QString::number(total_num+1),fileName,user_name,name,current_date_time.toString(),"0");
                //qDebug()<<str;
                QSqlQuery query;
                query.exec(str);
            }

        }
        else
        {
            QMessageBox mesg;
            mesg.warning(this,"警告","打开图片失败!");
            return;
        }

    flush();

}

void MainWindow::on_manage_clicked()
{
    manage_page_show = new manage_page();
    manage_page_show->setWindowTitle("管理");
    manage_page_show->show();
}

void MainWindow::on_flush_clicked()
{
    flush();
}


