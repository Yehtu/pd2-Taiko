#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T09:42:47
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    how.cpp

HEADERS  += mainwindow.h \
    game.h \
    how.h

FORMS    += mainwindow.ui \
    game.ui \
    how.ui

RESOURCES += \
    img.qrc
