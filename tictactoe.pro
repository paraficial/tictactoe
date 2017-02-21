#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T21:53:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tictactoe
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    agent.cpp \
    board.cpp \
    game.cpp \
    gamelogic.cpp \
    gamestate.cpp \
    humanplayer.cpp

HEADERS  += widget.h \
    agent.h \
    player.h \
    board.h \
    game.h \
    gamelogic.h \
    gamestate.h \
    humanplayer.h

FORMS    += widget.ui
