#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "gamestate.h"

class Player {
public:
    virtual void generateNextMove(int&, GameState*) = 0;
    virtual bool isHuman() = 0;
    virtual int getPlayerNumber() = 0;
};

#endif // PLAYER
