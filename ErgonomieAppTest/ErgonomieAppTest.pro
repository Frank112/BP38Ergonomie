#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T17:16:32
#
#-------------------------------------------------

QT       += core gui widgets testlib sql network


TARGET = EronomieappTest
CONFIG   += console c++11

TEMPLATE = app

unix {
    macx{
        QMAKE_CXXFLAGS += -stdlib=libc++
        QMAKE_CXXFLAGS += -std=c++11
        QMAKE_CXXFLAGS += -mmacosx-version-min=10.8
        QMAKE_LFLAGS += -mmacosx-version-min=10.8
    }
}

HEADERS += tst_dbhandlertest.h \
           tst_controllertest.h \
           ../databaseHandler/dbhandler.h \
           ../standardpaths.h \
           ../databaseHandler/dbconstants.h \
           ../control/controller.h \
           ../ftpHandler/ftphandler.h \
           ../xmlHandler/xmlparser.h \
           ../xmlHandler/xmlconstants.h \
           ../settings.h

SOURCES += main.cpp \
           tst_dbhandlertest.cpp \
           tst_controllertest.cpp \
           ../databaseHandler/dbhandler.cpp \
           ../databaseHandler/dbconstants.cpp \
           ../control/controller.cpp \
           ../ftpHandler/ftphandler.cpp \
           ../xmlHandler/xmlparser.cpp \
           ../xmlHandler/xmlconstants.cpp \
           ../settings.cpp


RESOURCES += ../testassets.qrc \
             ../assets.qrc

DEFINES += SRCDIR=\\\"$$PWD/\\\"
