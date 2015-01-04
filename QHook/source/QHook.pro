#-------------------------------------------------
#
# Project created by QtCreator 2015-01-04T08:22:48
#
#-------------------------------------------------

QT       -= gui

TARGET = QHook
TEMPLATE = lib
CONFIG += staticlib

win32:LIBS += -luser32

SOURCES += qhook.cpp \
    keyboardhook.cpp \
    qhookkeyevent.cpp \
    qhookmouseevent.cpp \
    mousehook.cpp \
    qhookwheelevent.cpp


HEADERS += qhook.h \
    keyboardhook.h \
    qhookkeyevent.h \
    qhookmouseevent.h \
    mousehook.h \
    qhookwheelevent.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}
