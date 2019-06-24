#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T23:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DMCompanion
TEMPLATE = app

QMAKE_CXXFLAGS += -O3 -std=c++17

SOURCES += main.cpp \
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
    sort.tpp \
    sort.cpp \
    spellmodel.cpp

HEADERS  += spellbook.h \
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
    spell_parse.h \
    sort.h \
    spellmodel.h

FORMS    += dmcompanion.ui \
    spellbook.ui \
    monstermanual.ui

UI_DIR = $$PWD

CONFIG    += c++17

DISTFILES += \
    BookBackground.jpeg \
    Spells.json \
    resources/bookbackground_2.jpg \
    star_filled.png \
    star_filled_2.png \
    star_empty.png \
    resources/Monsters.json

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/release/ -ldnd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/debug/ -ldnd
else:unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -ldnd

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/release/libdnd.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/debug/libdnd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/release/dnd.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/debug/dnd.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libdnd.a
