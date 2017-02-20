#ifndef AGENT_H
#define AGENT_H

#include "gamestate.h"
#include "gamelogic.h"
#include "player.h"

struct possibleMove{
    int move;
    int score;
    int depth;
};

class Agent: public Player{
private:
    GameLogic *logic;
    int playerNumber;
    bool human;

public:
    Agent(int);
    ~Agent();
    bool isHuman();
    int getPlayerNumber();

    void generateNextMove(int&, GameState*);
    possibleMove possibleMovesMinimum(possibleMove*, int);
    possibleMove possibleMovesMaximum(possibleMove*, int);
    int minimax(GameState*);
    int minValue(GameState*, int);
    int maxValue(GameState*, int);
    void printPossibleMoves(possibleMove*, int);
};

#endif // AGENT_H
