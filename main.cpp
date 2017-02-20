//#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <iostream>

#include "mywindow.h"
#include "board.h"
#include "agent.h"
#include "humanplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Player *player1 = new HumanPlayer(1);
    Player *player2 = new HumanPlayer(2);
    Player *player1 = new Agent(1);
//    Player *player2 = new Agent(2);

    Board *board = new Board(player1, player2);

    QWidget *window;
    window = new MyWindow(board);
//    MyWindow window(board);
    board->setParent(window);
    window->setWindowTitle("Tic Tac Toe");

    window->show();
    board->delay(500);
    board->run();
    return a.exec();
}
