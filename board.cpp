#include "board.h"
#include <cmath>

#include <iostream>
#include <QMouseEvent>


Board::Board(GameState *state, QWidget *parent) : QWidget(parent)
{
    tileSize = 100;

    setMaximumSize(3*tileSize, 3*tileSize);
    setMinimumSize(3*tileSize, 3*tileSize);
    setToolTip("Board");

    this->state = state;

    clicked = -1;
    allowed = false;
}

Board::~Board() {
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

void Board::mousePressEvent(QMouseEvent *e) {
    std::cout << state->getCurrentPlayer() << std::endl;

    if (allowed){
        std::cout << "mousePressEvent" << std::endl;

        // Get clicked tile
        int x, y;
        x = e->pos().rx() / 100;
        y = e->pos().ry() / 100;
        clicked = y*3 + x;
    }
}

void Board::getClicked(int& val) {
    val = this->clicked;
}

void Board::setAllowed(bool value) {
    this->allowed = value;
}
