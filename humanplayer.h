#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(int);
    void generateNextMove(int&, GameState*);
    bool isHuman();
    int getPlayerNumber();

private:
    int playerNumber;
    bool human;
};

#endif // HUMANPLAYER_H
