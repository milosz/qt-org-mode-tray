#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T22:46:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-org-mode-tray
TEMPLATE = app


SOURCES += main.cpp\
        systemtray.cpp \
    ideadialog.cpp

HEADERS  += systemtray.h \
    ideadialog.h

FORMS    += systemtray.ui \
    ideadialog.ui

RESOURCES += \
    trayicon.qrc
