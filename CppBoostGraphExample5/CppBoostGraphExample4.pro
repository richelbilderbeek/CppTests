include(../../RibiLibraries/DesktopApplication.pri)
include(../../RibiLibraries/Boost.pri)
include(../../RibiLibraries/Poppler.pri)
# unix {
#   LIBS += -L/usr/local/bin -lpoppler-qt4
# }

QT       += core gui xml
SOURCES += main.cpp \
        dialogmain.cpp
HEADERS  += dialogmain.h
FORMS    += dialogmain.ui
RESOURCES += CppBoostGraphExample4.qrc
