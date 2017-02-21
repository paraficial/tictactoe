#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <cmath>

class GameState {
private:
    int boardSize;
    int *board;
    int player1;
    int player2;
    int currentPlayer;

public:
    GameState(int, int);
    ~GameState();
    void printBoard();
    void makeMove(int&);
    void changePlayer();
    int otherPlayer(int);
    void deepCopy(GameState*);
    void initiate();

    int getBoardSize();
    int* getBoard();
    int getCurrentPlayer();
};

#endif // GAMESTATE_H
