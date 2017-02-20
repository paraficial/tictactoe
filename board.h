#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QCursor>
#include <QLabel>
#include "gamestate.h"
#include "gamelogic.h"
#include "player.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    Board(Player *p1 = 0, Player *p2 = 0, QWidget *parent = 0);
    ~Board();
    void performMove(int);
    void delay(int);

signals:

public slots:
    void run();
    void newGame();

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
    GameState *state;
    GameLogic *logic;
    Player *currentPlayer;
    Player *otherPlayer;
    QLabel *statusLabel;
    int tileSize;
    int clicked;
    bool allowed;
};

#endif // BOARD_H
