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
    gameloopthread.cpp \
    beizerCurve.cpp \
    Structs.cpp \
    aspectratiopixmaplabel.cpp \
    PlayerBeam.cpp \
    enemy.cpp

HEADERS  += mainwindow.h \
    menuwindow.h \
    Structs.h \
    threadpstart.h \
    gameloopthread.h \
    beizerCurve.h \
    aspectratiopixmaplabel.h \
    PlayerBeam.h \
    DataLibrary.h \
    enemy.h

FORMS    += mainwindow.ui \
    menuwindow.ui

RESOURCES += \
    assets.qrc
