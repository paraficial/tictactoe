#include "gamelogic.h"

GameLogic::GameLogic() {
}

void GameLogic::generateValidMoves(GameState *state, int *validMoves) {
    int validMovesCounter = 0;
    for (int i = 0; i < state->getBoardSize(); i++) {
        if (state->getBoard()[i] == 0) {
            validMoves[validMovesCounter] = i;
            validMovesCounter++;
        }
    }
}

int GameLogic::numOfValidMoves(GameState *state) {
    int result = 0;
    for (int i = 0; i < state->getBoardSize(); i++) {
        if (state->getBoard()[i] == 0) {
            result++;
        }
    }
    return result;
}

bool GameLogic::validMove(int &move, int *validMoves, int &size, GameState *state) {
    bool available = false;
    for (int i = 0; i < size; i++) {
        if (move == validMoves[i]) {
            available = true;
        }
    }
    return available & (0 <= move && move < state->getBoardSize());
}

bool GameLogic::gameOver(GameState *state) {
    bool gameOver = true;
    for (int i = 0; i < state->getBoardSize(); i++) {
        gameOver = gameOver & (state->getBoard()[i] != 0);
    }
    return gameOver;
}

bool GameLogic::gameWon(GameState *state) {
    int a = sqrt(state->getBoardSize());
    int *board = state->getBoard();

    for (int i = 0; i < a; i++) {
        bool row = true;
        bool col = true;
        bool diagonal1 = true;
        bool diagonal2 = true;

        for (int j = 0; j < a; j++) {
            row = row & (board[a*i+j] == state->otherPlayer(state->getCurrentPlayer()));
        }
        for (int j = 0; j < a; j++) {
            col = col & (board[a*j+i] == state->otherPlayer(state->getCurrentPlayer()));
        }
        for (int j = 0; j < a; j++) {
            diagonal1 = diagonal1 & (board[j*a+j] == state->otherPlayer(state->getCurrentPlayer()));
        }
        for (int j = 1; j <= a; j++) {
            diagonal2 = diagonal2 & (board[j*a-j] == state->otherPlayer(state->getCurrentPlayer()));
        }

        if (row || col || diagonal1 || diagonal2) return true;
    }
    return false;
}
