#include "agent.h"

Agent::Agent(int p) {
    logic = new GameLogic();
    playerNumber = p;
    human = false;
}

Agent::~Agent() {
    delete logic;
}

bool Agent::isHuman() {
    return human;
}

int Agent::getPlayerNumber() {
    return playerNumber;
}

void Agent::generateNextMove(int& move, GameState *state) {
    move = minimax(state);
}

possibleMove Agent::possibleMovesMaximum(possibleMove *arr, int size) {
    possibleMove result;
    if (size >= 1) {
        result = arr[0];
    }
    for (int i = 1; i < size; i++) {
        if (arr[i].score > result.score) {
            result = arr[i];
        }
    }
    return result;
}

possibleMove Agent::possibleMovesMinimum(possibleMove *arr, int size) {
    possibleMove result;
    if (size >= 1) {
        result = arr[0];
    }
    for (int i = 1; i < size; i++) {
        if (arr[i].score < result.score) {
            result = arr[i];
        }
    }
    return result;
}

void Agent::printPossibleMoves(possibleMove *arr, int size) {
    std::cout << "possibleMoves: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i << ": " << arr[i].move << ", " << arr[i].score << ", " << arr[i].depth << std::endl;
    }
}

int Agent::maxValue(GameState *state, int depth) {
    int newDepth = depth + 1;
    if (logic->gameWon(state)) {
        return -1;
    }
    if (logic->gameOver(state)) {
        return 0;
    }

    int vmSize = logic->numOfValidMoves(state);
    int validMoves[state->getBoardSize()];
    logic->generateValidMoves(state, validMoves);

    possibleMove *moves;
    moves = new possibleMove[vmSize];

    for (int i = 0; i < vmSize; i++) {
        GameState *nState;
        int boardSize = state->getBoardSize();
        int currentPlayer = state->getCurrentPlayer();
        nState = new GameState(boardSize, currentPlayer);
        state->deepCopy(nState);
        nState->makeMove(validMoves[i]);

        moves[i].move = validMoves[i];
        moves[i].score = minValue(nState, newDepth);
        moves[i].depth = depth;
    }
    return possibleMovesMaximum(moves, vmSize).score;
}

int Agent::minValue(GameState *state, int depth) {
    int newDepth = depth + 1;
    if (logic->gameWon(state)) {
        return 1;
    }
    if (logic->gameOver(state)) {
        return 0;
    }

    int vmSize = logic->numOfValidMoves(state);
    int validMoves[state->getBoardSize()];
    logic->generateValidMoves(state, validMoves);

    possibleMove *moves;
    moves = new possibleMove[vmSize];

    for (int i = 0; i < vmSize; i++) {
        GameState *nState;
        int boardSize = state->getBoardSize();
        int currentPlayer = state->getCurrentPlayer();
        nState = new GameState(boardSize, currentPlayer);
        state->deepCopy(nState);
        nState->makeMove(validMoves[i]);

        moves[i].move = validMoves[i];
        moves[i].score = maxValue(nState, newDepth);
        moves[i].depth = depth;
    }

//	printPossibleMoves(moves, vmSize);
    return possibleMovesMinimum(moves, vmSize).score;
}

int Agent::minimax(GameState *state) {
    int depth = 0;

    int vmSize = logic->numOfValidMoves(state);
    int validMoves[state->getBoardSize()];
    logic->generateValidMoves(state, validMoves);

    possibleMove *moves;
    moves = new possibleMove[vmSize];

    for (int i = 0; i < vmSize; i++) {
        GameState *nState;
        int boardSize = state->getBoardSize();
        int currentPlayer = state->getCurrentPlayer();
        nState = new GameState(boardSize, currentPlayer);
        state->deepCopy(nState);
        nState->makeMove(validMoves[i]);

        moves[i].move = validMoves[i];
        moves[i].score = minValue(nState, depth);
        moves[i].depth = depth;
    }

    printPossibleMoves(moves, vmSize);
    return possibleMovesMaximum(moves, vmSize).move;
}
