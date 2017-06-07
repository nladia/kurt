#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T12:14:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGame
TEMPLATE = app


SOURCES += main.cpp\
        startgame.cpp \
    pers.cpp \
    startroom.cpp \
    weapon.cpp \
    looser.cpp \
    roombattle.cpp \
    monster.cpp \
    room.cpp \
    loot.cpp \
    map.cpp \
    floor.cpp \
    shop.cpp \
    ability.cpp

HEADERS  += startgame.h \
    pers.h \
    startroom.h \
    weapon.h \
    looser.h \
    roombattle.h \
    monster.h \
    room.h \
    loot.h \
    map.h \
    floor.h \
    shop.h \
    ability.h

FORMS    += startgame.ui \
    startroom.ui \
    looser.ui \
    roombattle.ui \
    loot.ui \
    map.ui \
    shop.ui \
    floor.ui \
    ability.ui
