#-------------------------------------------------
#
# Project created by QtCreator 2015-04-19T19:10:27
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
#QT       += uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library_Manage_System
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    rootdialog.cpp \
    addadmidialog.cpp \
    admidialog.cpp \
    deleteadmidialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    rootdialog.h \
    addadmidialog.h \
    admidialog.h \
    deleteadmidialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    rootdialog.ui \
    addadmidialog.ui \
    admidialog.ui \
    deleteadmidialog.ui
CONFIG +=console
