#-------------------------------------------------
#
# Project created by QtCreator 2014-05-12T19:22:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GaussianBlur
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imageloader.cpp \
    gaussianblur.cpp

HEADERS  += mainwindow.h \
    imageloader.h \
    gaussianblur.h

FORMS    += mainwindow.ui
