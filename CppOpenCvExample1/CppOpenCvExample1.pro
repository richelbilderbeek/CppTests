#-------------------------------------------------
#
# Project created by QtCreator 2012-07-11T13:49:58
#
#-------------------------------------------------

QT       += core

QT       -= gui

unix {
   CONFIG += link_pkgconfig
   PKGCONFIG += opencv
}

#LIBS += -lopencv

TARGET = CppOpenCvExample1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

RESOURCES += \
    CppOpenCvExample1.qrc
