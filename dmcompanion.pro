#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T23:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DMCompanion
TEMPLATE = app

QMAKE_CXX = gcc-7
QMAKE_CXXFLAGS += -O3 -std=c++17

SOURCES += main.cpp \
    qdisplay.cpp \
    dmcompanion.cpp \
    jsoncpp/jsoncpp.cpp \
    monster_display.cpp \
    profile.cpp \
    qhelpers.cpp \
    spellbook.cpp \
    monstermanual.cpp \
    qparse.cpp \
    monster_parse.cpp \
    json_helpers.cpp \
    spell_parse.cpp \
    spellmodel.cpp

HEADERS  += spellbook.h \
    monster_display.tpp \
    monster_sort_field.h \
    qdisplay.h \
    dmcompanion.h \
    jsoncpp/json/json.h \
    jsoncpp/json/json-forwards.h \
    monster_display.h \
    monstermanual.h \
    profile.h \
    qhelpers.h \
    qparse.h \
    json_helpers.h \
    monster_parse.h \
    sort.hpp \
    spell_parse.h \
    spell_sort_field.h \
    spellmodel.h

FORMS    += dmcompanion.ui \
    spellbook.ui \
    monstermanual.ui

UI_DIR = $$PWD

CONFIG    += c++17

DISTFILES += \
    BookBackground.jpeg \
    MonsterFields.txt \
    Spells.json \
    resources/bookbackground_2.jpg \
    star_filled.png \
    star_filled_2.png \
    star_empty.png \
    resources/Monsters.json

RESOURCES += \
    fonts.qrc \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += /usr/local/lib/release/ -ldnd
else:win32:CONFIG(debug, debug|release): LIBS += -L/usr/local/lib/debug/ -ldnd
else:unix: LIBS += -L/usr/local/lib/ -ldnd

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += /usr/local/lib/release/libdnd.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += /usr/local/lib/debug/libdnd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += /usr/local/lib/release/dnd.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += /usr/local/lib/debug/dnd.lib
else:unix: PRE_TARGETDEPS += /usr/local/lib/libdnd.a
