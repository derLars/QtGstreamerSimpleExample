#-------------------------------------------------
#
# Project created by QtCreator 2017-02-24T10:04:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GStreamerExample
TEMPLATE = app

#sudo apt-get install libgstreamer1.0-dev
#sudo apt-get install libgstreamer-plugins-base1.0-dev

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-1.0 gstreamer-video-1.0

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
