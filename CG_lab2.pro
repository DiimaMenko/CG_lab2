#-------------------------------------------------
#
# Project created by QtCreator 2016-03-23T12:57:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG_lab2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    point.cpp \
    polygon.cpp \
    segment.cpp

HEADERS  += mainwindow.h \
    point.h \
    polygon.h \
    segment.h

FORMS    += mainwindow.ui
