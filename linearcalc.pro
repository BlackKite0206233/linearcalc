#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T21:32:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = linearcalc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Mat.cpp \
    Vec.cpp

HEADERS  += mainwindow.h \
    Mat.h \
    Vec.h

FORMS    += mainwindow.ui
