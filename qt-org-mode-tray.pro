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
    ideadialog.cpp \
    tododialog.cpp \
    bkmkdialog.cpp

HEADERS  += systemtray.h \
    ideadialog.h \
    tododialog.h \
    bkmkdialog.h

FORMS    += systemtray.ui \
    ideadialog.ui \
    tododialog.ui \
    bkmkdialog.ui

RESOURCES += \
    trayicon.qrc
