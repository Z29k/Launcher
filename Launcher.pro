#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T10:52:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Launcher
TEMPLATE = app


SOURCES += main.cpp\
        launcher.cpp \
    applications.cpp

HEADERS  += launcher.h \
    applications.h

FORMS    += launcher.ui

DISTFILES += \
    ../build-Launcher-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/debug/apps.json
