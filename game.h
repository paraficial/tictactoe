#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "gamelogic.h"
#include "board.h"
#include "board.h"
#include <QWidget>
#include <QApplication>
#include <QTimer>
#include <QTime>

class Game : public QWidget
{
    Q_OBJECT

private:
    Player *player1;
    Player *player2;
    Player *player3;
    Player *player4;
    Player *currentPlayer;
    Player *currentPlayer1;
    Player *currentPlayer2;
    Player *nextPlayer1;
    Player *nextPlayer2;
    Board *board;

    GameLogic *logic;
    GameState *state;
    void setNextMove(int&);

public:
    Game(Player*, Player*, Player*, Player*, Board*, GameState*, QWidget *parent = 0);
    QTimer *timer;
    int nextMove;
    void changePlayers();
    void delay(int);

public slots:
    void nextRound();
    void restart();
    void changeNextPlayer1(QString);
    void changeNextPlayer2(QString);
};

#endif // GAME_H
