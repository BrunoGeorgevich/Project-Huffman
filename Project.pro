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
    codification.cpp \
    menu_inicial.cpp \
    encodingTree.cpp \
    decodingtree.cpp \
    encodingNode.cpp \
    warning.cpp \
    tela_compressao.cpp \
    tela_descompressao.cpp

HEADERS += \
    data_file.h \
    codification.h \
    menu_inicial.h \
    encodingTree.h \
    decodingtree.h \
    encodingNode.h \
    decodingNode.h \
    warning.h \
    tela_compressao.h \
    tela_descompressao.h

FORMS += \
    menu_inicial.ui \
    warning.ui \
    tela_compressao.ui \
    tela_descompressao.ui

RESOURCES += \
    Multimedia.qrc
