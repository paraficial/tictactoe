#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gamestate.h"

class GameLogic {
    public:
    GameLogic();
    void generateValidMoves(GameState*, int*);
    bool validMove(int&, int*, int&, GameState*);
    bool gameWon(GameState*);
    int numOfValidMoves(GameState*);
    bool gameOver(GameState*);
};

#endif // GAMELOGIC_H
