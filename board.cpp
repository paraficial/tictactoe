#include "board.h"
#include <cmath>
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include "humanplayer.h"
#include <QApplication>
#include <QTime>
#include "mywindow.h"


Board::Board(QWidget *parent) : QWidget(parent)
{

}

Board::Board(Player *p1, Player *p2, QWidget *parent) : QWidget(parent)
{
    currentPlayer = p1;
    otherPlayer = p2;
    state = new GameState(9, 1);
    logic = new GameLogic();

    tileSize = 100;

    setMaximumSize(3*tileSize, 3*tileSize);
    setMinimumSize(3*tileSize, 3*tileSize);
    setToolTip("Board");

    clicked = -1;
    if (currentPlayer->isHuman()) {
        allowed = true;
    }
    else {
        allowed = false;
    }
}

Board::~Board() {
    delete state;
}

void Board::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#000000"), 4));

    int a = sqrt(state->getBoardSize());

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            switch(state->getBoard()[i*a+j]) {
            case 0:
                painter.setBrush(QBrush("#ffffff"));
                painter.drawRect(j*tileSize, i*tileSize, j*tileSize+tileSize, i*tileSize+tileSize);
                break;
            case 1:
                painter.setBrush(QBrush("#ffffff"));
                painter.drawRect(j*tileSize, i*tileSize, j*tileSize+tileSize, i*tileSize+tileSize);
                painter.setBrush(QBrush("#000000"));
                painter.drawLine(j*tileSize+10, i*tileSize+10, j*tileSize+tileSize-10, i*tileSize+tileSize-10);
                painter.drawLine(j*tileSize+10, i*tileSize+tileSize-10, j*tileSize+tileSize-10, i*tileSize+10);
                break;
            case 2:
                painter.setBrush(QBrush("#ffffff"));
                painter.drawRect(j*tileSize, i*tileSize, j*tileSize+tileSize, i*tileSize+tileSize);
                painter.setBrush(QBrush("#000000"));
                painter.drawEllipse(j*tileSize+10, i*tileSize+10, 80, 80);
                painter.setBrush(QBrush("#ffffff"));
                painter.drawEllipse(j*tileSize+12, i*tileSize+12, 76, 76);
                break;
            }
        }
    }
}

void Board::run() {
    if (!currentPlayer->isHuman()) {
        allowed = false;
        int move = -1;
        int vmSize = logic->numOfValidMoves(state);
        int validMoves[vmSize];
        logic->generateValidMoves(state, validMoves); // is changed by the function.

        while (!logic->validMove(move, validMoves, vmSize, state)) {
            currentPlayer->generateNextMove(move, state);
            if (!logic->validMove(move, validMoves, vmSize, state)) {
                std::cout << "Invalid move" << std::endl;
            }
        }
        performMove(move);

        if (currentPlayer->isHuman()) {
            allowed = true;
        }
        else {
            run();
        }
    }
}

void Board::mousePressEvent(QMouseEvent *e) {
    std::cout << state->getCurrentPlayer() << std::endl;

    if (allowed){
        // Get clicked tile
        int x, y;
        x = e->pos().rx() / 100;
        y = e->pos().ry() / 100;
        clicked = y*3 + x;

        int vmSize = logic->numOfValidMoves(state);
        int validMoves[vmSize];
        logic->generateValidMoves(state, validMoves);

        if (logic->validMove(clicked, validMoves, vmSize, state)) {
            performMove(clicked);
            run();
        }
    }
}

void Board::performMove(int move) {
    state->makeMove(move);
    update();

    Player *tmp = currentPlayer;
    currentPlayer = otherPlayer;
    otherPlayer = tmp;

    delay(500);
    if (logic->gameOver(state)) {
        std::cout << "Game Over" << std::endl;
        allowed = false;
        newGame();
    }
    else if (logic->gameWon(state)) {
        std::cout << "so won" << std::endl;
        allowed = false;
        newGame();
    }
}

void Board::newGame() {
    allowed = false;
    GameState *newState = new GameState(9, 1);
    delete state;
    state = newState;
    if (currentPlayer->getPlayerNumber() != 1) {
        Player *tmp = currentPlayer;
        currentPlayer = otherPlayer;
        otherPlayer = tmp;
    }
    update();
    delay(500);
    run();
}

void Board::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
