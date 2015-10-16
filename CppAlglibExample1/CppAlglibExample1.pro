include(../../RibiLibraries/ConsoleApplication.pri)
include(../../RibiLibraries/Boost.pri)

SOURCES += main.cpp

#
#
# alglib
#
#

unix {
  message(Linux: alglib)
  INCLUDEPATH += ../../RibiLibraries/alglib-3.8.0/src

SOURCES += \
    ../../RibiLibraries/alglib-3.8.0/src/statistics.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/specialfunctions.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/solvers.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/optimization.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/linalg.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/interpolation.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/integration.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/fasttransforms.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/diffequations.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/dataanalysis.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/ap.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/alglibmisc.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/alglibinternal.cpp

HEADERS += \
    ../../RibiLibraries/alglib-3.8.0/src/statistics.h \
    ../../RibiLibraries/alglib-3.8.0/src/specialfunctions.h \
    ../../RibiLibraries/alglib-3.8.0/src/solvers.h \
    ../../RibiLibraries/alglib-3.8.0/src/optimization.h \
    ../../RibiLibraries/alglib-3.8.0/src/linalg.h \
    ../../RibiLibraries/alglib-3.8.0/src/interpolation.h \
    ../../RibiLibraries/alglib-3.8.0/src/integration.h \
    ../../RibiLibraries/alglib-3.8.0/src/fasttransforms.h \
    ../../RibiLibraries/alglib-3.8.0/src/diffequations.h \
    ../../RibiLibraries/alglib-3.8.0/src/dataanalysis.h \
    ../../RibiLibraries/alglib-3.8.0/src/ap.h \
    ../../RibiLibraries/alglib-3.8.0/src/alglibmisc.h \
    ../../RibiLibraries/alglib-3.8.0/src/alglibinternal.h
}

win32 {
  message(Windows: alglib)
  INCLUDEPATH += ../../RibiLibraries/alglib-3.8.0/src

SOURCES += \
    ../../RibiLibraries/alglib-3.8.0/src/statistics.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/specialfunctions.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/solvers.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/optimization.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/linalg.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/interpolation.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/integration.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/fasttransforms.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/diffequations.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/dataanalysis.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/ap.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/alglibmisc.cpp \
    ../../RibiLibraries/alglib-3.8.0/src/alglibinternal.cpp

HEADERS += \
    ../../RibiLibraries/alglib-3.8.0/src/statistics.h \
    ../../RibiLibraries/alglib-3.8.0/src/specialfunctions.h \
    ../../RibiLibraries/alglib-3.8.0/src/solvers.h \
    ../../RibiLibraries/alglib-3.8.0/src/optimization.h \
    ../../RibiLibraries/alglib-3.8.0/src/linalg.h \
    ../../RibiLibraries/alglib-3.8.0/src/interpolation.h \
    ../../RibiLibraries/alglib-3.8.0/src/integration.h \
    ../../RibiLibraries/alglib-3.8.0/src/fasttransforms.h \
    ../../RibiLibraries/alglib-3.8.0/src/diffequations.h \
    ../../RibiLibraries/alglib-3.8.0/src/dataanalysis.h \
    ../../RibiLibraries/alglib-3.8.0/src/ap.h \
    ../../RibiLibraries/alglib-3.8.0/src/alglibmisc.h \
    ../../RibiLibraries/alglib-3.8.0/src/alglibinternal.h
}
