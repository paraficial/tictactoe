#include "humanplayer.h"

HumanPlayer::HumanPlayer(int n)
{
    playerNumber = n;
    human = true;
}

void HumanPlayer::generateNextMove(int& move, GameState*) {
        std::cin >> move;
}

bool HumanPlayer::isHuman() {
    return human;
}

int HumanPlayer::getPlayerNumber() {
    return playerNumber;
}
