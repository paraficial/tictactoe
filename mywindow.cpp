#include "mywindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

#include "board.h"
#include "gamestate.h"
#include "agent.h"
#include "humanplayer.h"

MyWindow::MyWindow(Board *board, QWidget *parent) : QWidget(parent)
{
   //board->setParent(this);
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *buttons = new QHBoxLayout();

    statusLabel = new QLabel("Have Fun", this);
    QPushButton *quit = new QPushButton("Quit", this);
    QPushButton *restart = new QPushButton("Restart", this);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(restart, &QPushButton::clicked, board, &Board::newGame);

    vbox->addWidget(board);
    vbox->addWidget(statusLabel, 1, Qt::AlignTop);

    buttons->addWidget(restart);
    buttons->addWidget(quit);

    vbox->addLayout(buttons);

    setLayout(vbox);
}

MyWindow::~MyWindow() {

}

void MyWindow::updateLabel(QString s) {
    statusLabel->setText(s);
}
