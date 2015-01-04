#-------------------------------------------------
#
# Project created by QtCreator 2015-01-04T08:22:48
#
#-------------------------------------------------

QT       -= gui

TARGET = QHook
TEMPLATE = lib
CONFIG += staticlib

SOURCES += qhook.cpp \
    qhookkeyevent.cpp \
    qhookmouseevent.cpp

HEADERS += qhook.h \
    keyboardhook.h \
    qhookkeyevent.h \
    qhookmouseevent.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
