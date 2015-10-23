include(../../RibiLibraries/ConsoleApplication.pri)
include(../../RibiLibraries/Boost.pri)

INCLUDEPATH += \
    ../../RibiLibraries/Apfloat

HEADERS += \
    ../../RibiLibraries/Apfloat/ap.h \
    ../../RibiLibraries/Apfloat/apcplx.h \
    ../../RibiLibraries/Apfloat/apfloat.h \
    ../../RibiLibraries/Apfloat/apint.h \
    ../../RibiLibraries/Apfloat/aprat.h \
    ../../RibiLibraries/Apfloat/baseint.h \
    ../../RibiLibraries/Apfloat/bigint.h \
    ../../RibiLibraries/Apfloat/modint.h \
    ../../RibiLibraries/Apfloat/raw.h \
    ../../RibiLibraries/Apfloat/tapfloat.h

SOURCES += \
    ../../RibiLibraries/Apfloat/apcfunc.cpp \
    ../../RibiLibraries/Apfloat/apcplx.cpp \
    ../../RibiLibraries/Apfloat/apfloat.cpp \
    ../../RibiLibraries/Apfloat/apfunc.cpp \
    ../../RibiLibraries/Apfloat/apifunc.cpp \
    ../../RibiLibraries/Apfloat/apint.cpp \
    ../../RibiLibraries/Apfloat/aprat.cpp \
    ../../RibiLibraries/Apfloat/aprfunc.cpp \
    ../../RibiLibraries/Apfloat/apstruct.cpp \
    ../../RibiLibraries/Apfloat/baseint.cpp \
    ../../RibiLibraries/Apfloat/bigint.cpp \
    ../../RibiLibraries/Apfloat/carrycrt.cpp \
    ../../RibiLibraries/Apfloat/convolut.cpp \
    ../../RibiLibraries/Apfloat/crt.cpp \
    ../../RibiLibraries/Apfloat/datastru.cpp \
    ../../RibiLibraries/Apfloat/file.cpp \
    ../../RibiLibraries/Apfloat/fnt.cpp \
    ../../RibiLibraries/Apfloat/fourstep.cpp \
    ../../RibiLibraries/Apfloat/global.cpp \
    ../../RibiLibraries/Apfloat/init.cpp \
    ../../RibiLibraries/Apfloat/modfunc.cpp \
    ../../RibiLibraries/Apfloat/move.cpp \
    ../../RibiLibraries/Apfloat/scramble.cpp \
    ../../RibiLibraries/Apfloat/sixstep.cpp \
    ../../RibiLibraries/Apfloat/tablefnt.cpp \
    ../../RibiLibraries/Apfloat/tablefou.cpp \
    ../../RibiLibraries/Apfloat/tablesit.cpp \
    ../../RibiLibraries/Apfloat/tablesix.cpp \
    ../../RibiLibraries/Apfloat/tabletwo.cpp \
    ../../RibiLibraries/Apfloat/tabletwt.cpp \
    ../../RibiLibraries/Apfloat/tapfloat.cpp \
    ../../RibiLibraries/Apfloat/tapfunc.cpp \
    ../../RibiLibraries/Apfloat/tapstruc.cpp \
    ../../RibiLibraries/Apfloat/transpos.cpp \
    ../../RibiLibraries/Apfloat/wfta_asm.cpp

SOURCES += main.cpp

