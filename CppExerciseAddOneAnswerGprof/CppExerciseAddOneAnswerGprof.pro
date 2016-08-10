QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror -std=c++14

CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

#include(../../RibiLibraries/ConsoleApplication.pri)
include(../../RibiLibraries/Boost.pri)
include(../../RibiLibraries/Gprof.pri)

SOURCES += main.cpp


