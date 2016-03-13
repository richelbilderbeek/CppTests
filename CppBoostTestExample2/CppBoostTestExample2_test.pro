CONFIG += console
CONFIG -= app_bundle
QT -= core gui
TEMPLATE = app

QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror -std=c++11

SOURCES += \
    my_functions.cpp

HEADERS += \
    my_functions.h

SOURCES += test_my_functions.cpp

LIBS += -lboost_unit_test_framework
