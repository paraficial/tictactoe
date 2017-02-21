#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QStringList>

#include "board.h"
#include "board.h"
#include "gamestate.h"
#include "agent.h"
#include "humanplayer.h"

Widget::Widget(Board *board, Game *game, QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout(this);
    QVBoxLayout *vbox = new QVBoxLayout();
    QVBoxLayout *players = new QVBoxLayout();
    QHBoxLayout *buttons = new QHBoxLayout();

    statusLabel = new QLabel("Have Fun", this);

    QPushButton *quit = new QPushButton("Quit", this);
    QPushButton *restart = new QPushButton("Restart", this);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(restart, &QPushButton::clicked, game, &Game::restart);

    QStringList *pselection;
    pselection = new QStringList();
    pselection->append("");
    pselection->append("Human");
    pselection->append("Computer");

    combo1 = new QComboBox();
    combo1->addItems(*pselection);
    combo2 = new QComboBox();
    combo2->addItems(*pselection);

    connect(combo1, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated), game, &Game::changeNextPlayer1);
    connect(combo2, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated), game, &Game::changeNextPlayer2);

    vbox->addWidget(board);
    vbox->addWidget(statusLabel, 1, Qt::AlignTop);

    buttons->addWidget(restart);
    buttons->addWidget(quit);

    vbox->addLayout(buttons);

    hbox->addLayout(vbox);

    players->addWidget(combo1, 0);
    players->addWidget(combo2, 1, Qt::AlignTop);
    hbox->addLayout(players);

    setLayout(hbox);
}

Widget::~Widget() {

}
