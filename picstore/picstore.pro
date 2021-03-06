#-------------------------------------------------
#
# Project created by QtCreator 2021-06-19T20:31:40
#
#-------------------------------------------------

QT       += core gui
QT        += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = picstore
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    pic_show.cpp \
    regist.cpp \
    pic_info.cpp \
    big_pic.cpp \
    artist_page.cpp \
    user_page.cpp \
    manage_page.cpp \
    check_page.cpp \
    change_info.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    pic_show.h \
    regist.h \
    pic_info.h \
    big_pic.h \
    artist_page.h \
    user_page.h \
    manage_page.h \
    check_page.h \
    change_info.h

FORMS += \
        mainwindow.ui \
    login.ui \
    pic_show.ui \
    regist.ui \
    big_pic.ui \
    artist_page.ui \
    user_page.ui \
    manage_page.ui \
    check_page.ui \
    change_info.ui
