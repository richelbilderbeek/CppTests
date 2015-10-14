QT       += core
QT       -= gui

unix {
   CONFIG += link_pkgconfig
   PKGCONFIG += opencv
}

#LIBS += -lopencv

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp
