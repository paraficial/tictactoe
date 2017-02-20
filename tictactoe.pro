#-------------------------------------------------
#
# Project created by QtCreator 2017-02-17T17:05:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tictactoe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywindow.cpp \
    board.cpp \
    humanplayer.cpp \
    agent.cpp \
    gamestate.cpp \
    gamelogic.cpp

HEADERS  += mainwindow.h \
    mywindow.h \
    board.h \
    player.h \
    humanplayer.h \
    agent.h \
    gamestate.h \
    gamelogic.h

FORMS    += mainwindow.ui
