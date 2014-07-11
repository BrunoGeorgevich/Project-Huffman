#-------------------------------------------------
#
# Project created by QtCreator 2014-06-03T08:10:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    data_file.cpp \
    tree.cpp \
    node.cpp \
    codification.cpp \
    menu_inicial.cpp

HEADERS += \
    data_file.h \
    tree.h \
    node.h \
    codification.h \
    menu_inicial.h

FORMS += \
    menu_inicial.ui
