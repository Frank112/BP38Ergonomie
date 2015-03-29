#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T17:16:32
#
#-------------------------------------------------

QT       += core testlib sql

QT       -= gui

TARGET = tst_dbhandlertest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -framework CoreFoundation

unix {
    macx{
        QMAKE_CXXFLAGS += -stdlib=libc++
        QMAKE_CXXFLAGS += -std=c++11
        QMAKE_CXXFLAGS += -mmacosx-version-min=10.8
        QMAKE_LFLAGS += -mmacosx-version-min=10.8
    }
}

SOURCES += tst_dbhandlertest.cpp \
           $$PWD/../databaseHandler/dbHandler.cpp
HEADERS += ../databaseHandler/dbHandler.h \
           ../standardpaths.h

RESOURCES += ../testassets.qrc

DEFINES += SRCDIR=\\\"$$PWD/\\\"
