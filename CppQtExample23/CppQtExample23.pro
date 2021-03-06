exists(../../DesktopApplication.pri) {
  include(../../DesktopApplication.pri)
}
!exists(../../DesktopApplication.pri) {
  QT += core gui
  greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
  TEMPLATE = app

  CONFIG(debug, debug|release) {
    message(Debug mode)
  }

  CONFIG(release, debug|release) {
    message(Release mode)
    DEFINES += NDEBUG NTRACE_BILDERBIKKEL
  }

  QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

  unix {
    QMAKE_CXXFLAGS += -Werror
  }
}

exists(../../Libraries/Boost.pri) {
  include(../../Libraries/Boost.pri)
}
!exists(../../Libraries/Boost.pri) {
  win32 {
    INCLUDEPATH += \
      ../../../Projects/Libraries/boost_1_55_0
  }
}

SOURCES += \
  main.cpp \
  grabmedialog.cpp
HEADERS  += grabmedialog.h
FORMS    += grabmedialog.ui

#CONFIG += mobility
#MOBILITY =
#symbian {
#    TARGET.UID3 = 0xe7eb3159
#    # TARGET.CAPABILITY +=
#    TARGET.EPOCSTACKSIZE = 0x14000
#    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
#}
