#-------------------------------------------------
#
# Project created by QtCreator 2018-07-16T08:25:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mota
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    gamewindow.cpp \
    info.cpp \
    block.cpp \
    hero.cpp \
    monster.cpp \
    floor.cpp \
    brick.cpp \
    door.cpp \
    prop.cpp \
    start.cpp \
    businessman.cpp \
    shop.cpp \
    princess.cpp \
    mbhero.cpp

HEADERS += \
        widget.h \
    gamewindow.h \
    info.h \
    block.h \
    hero.h \
    monster.h \
    floor.h \
    brick.h \
    door.h \
    prop.h \
    start.h \
    businessman.h \
    shop.h \
    princess.h \
    mbhero.h

FORMS += \
        widget.ui \
    start.ui

RESOURCES += \
    mymap.qrc
