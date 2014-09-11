#-------------------------------------------------
#
# Project created by QtCreator 2014-09-09T17:12:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Galaga
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    menuwindow.cpp \
    threadpstart.cpp \
    userinputhandler.cpp \
    gameloopthread.cpp \
    beizerCurve.cpp

HEADERS  += mainwindow.h \
    menuwindow.h \
    Structs.h \
    threadpstart.h \
    userinputhandler.h \
    gameloopthread.h \
    beizerCurve.h

FORMS    += mainwindow.ui \
    menuwindow.ui

RESOURCES += \
    assets.qrc
