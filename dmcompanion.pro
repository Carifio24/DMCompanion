#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T23:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DMCompanion
TEMPLATE = app

QMAKE_CXXFLAGS += -O3

SOURCES += main.cpp \
    dmcompanion.cpp \
    Parse.cpp \
    Filter.cpp \
    Sort.cpp \
    Parse.tpp \
    Sort.tpp \
    jstring.cpp \
    jsoncpp/jsoncpp.cpp \
    spellbook.cpp \
    Spell.cpp \
    monstermanual.cpp \
    alignment.cpp \
    fraction.cpp \
    ability.cpp \
    action.cpp \
    enummaps.cpp

HEADERS  += spellbook.h \
    dmcompanion.h \
    Sort.h \
    Parse.h \
    Filter.h \
    jsoncpp/json/json.h \
    jsoncpp/json/json-forwards.h \
    jstring.h \
    Enumerations.h \
    Spell.h \
    Monster.h \
    action.h \
    ability.h \
    monstermanual.h \
    alignment.h \
    fraction.h \
    enummaps.h \
    damageinfo.h

FORMS    += dmcompanion.ui \
    spellbook.ui \
    monstermanual.ui

CONFIG    += c++14

DISTFILES += \
    BookBackground.jpeg \
    Spells.json \
    star_filled.png \
    star_filled_2.png \
    star_empty.png \
    resources/Monsters.json

RESOURCES += \
    resources.qrc
