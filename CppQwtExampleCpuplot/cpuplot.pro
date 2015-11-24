include(../../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../../RibiLibraries/Qwt_6_1.pri)
include(../../RibiLibraries/Qwt_6_1_2.pri)

LIBS += -lqwt

HEADERS =  \
    cpuplot.h \
    cpustat.h \
    cpupiemarker.h 

SOURCES = \
    cpuplot.cpp \
    cpustat.cpp \
    cpupiemarker.cpp 
