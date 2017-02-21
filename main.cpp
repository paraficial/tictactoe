#include <QApplication>
#include <QIcon>
#include <iostream>

#include "widget.h"
#include "board.h"
#include "board.h"
#include "agent.h"
#include "humanplayer.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Player *player1 = new HumanPlayer(1);
    Player *player2 = new HumanPlayer(2);
    Player *player3 = new Agent(1);
    Player *player4 = new Agent(2);

    GameState *state = new GameState(9, player1->getPlayerNumber());
    Board *board = new Board(state);
    Game *game = new Game(player1, player2, player3, player4, board, state);

    Widget *window;
    window = new Widget(board, game);

    board->setParent(window);
    window->setWindowTitle("Tic Tac Toe");

    window->show();

    game->nextRound();
    return a.exec();
}
