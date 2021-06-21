#include "mainwindow.h"
#include "pic_show.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    //Pic_Show *widget=new Pic_Show();
    //w.putwidget(widget);
    return a.exec();
}
