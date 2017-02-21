#include "game.h"

Game::Game(Player *player1, Player *player2, Player *player3, Player *player4, Board *board, GameState *state, QWidget *parent) : QWidget(parent)
{
    this->player1 = player1;
    this->player2 = player2;
    this->player3 = player3;
    this->player4 = player4;
    this->currentPlayer1 = player1;
    this->currentPlayer2 = player3;
    this->nextPlayer1 = player1;
    this->nextPlayer2 = player3;

    this->currentPlayer = currentPlayer1;

    this->board = board;
    this->state = state;
    logic = new GameLogic();
    nextMove = -1;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Game::nextRound);

}

void Game::changeNextPlayer1(QString s) {
    std::cout << "changePlayer1" << std::endl;
    if (s == "Human") {
        std::cout << "it's player1 now" << std::endl;
        this->nextPlayer1 = player1;
    }
    else if (s == "Computer") {
        std::cout << "it's player3 now" << std::endl;
        this->nextPlayer1 = player3;
    }
}

void Game::changeNextPlayer2(QString s) {
    std::cout << "changePlayer2" << std::endl;
    if (s == "Human") {
        this->nextPlayer2 = player2;
    }
    else if (s == "Computer") {
        this->nextPlayer2 = player4;
    }
}

void Game::changePlayers() {
    if (currentPlayer == currentPlayer1) {
        std::cout << "this worked" << std::endl;
        currentPlayer = currentPlayer2;
    }
    else if (currentPlayer == currentPlayer2) {
        currentPlayer = currentPlayer1;
    }
}

void Game::restart() {
    this->currentPlayer1 = this->nextPlayer1;
    this->currentPlayer2 = this->nextPlayer2;
    this->currentPlayer = this->currentPlayer1;
    state->initiate();
    board->clicked = -1;
    board->update();
    nextRound();
}

void Game::nextRound()
{
    delay(100);
    if (!(logic->gameOver(state) || logic->gameWon(state))) {
        if (currentPlayer->isHuman()) {
            board->setAllowed(true);
            board->getClicked(nextMove);
            if (nextMove != -1) {
                setNextMove(nextMove);
            }
            else {
                timer->start(100);
            }
        }
        else if (!currentPlayer->isHuman()) {
            currentPlayer->generateNextMove(nextMove, state);
            setNextMove(nextMove);
        }
    }
    else {
        timer->stop();
        if (logic->gameWon(state)) {
            std::cout << "The game has ended, and Player " << state->otherPlayer(state->getCurrentPlayer()) << " has won!" << std::endl;
        }
        else {
            std::cout << "No more moves are possible." << std::endl;
        }
    }
}

void Game::setNextMove(int &move) {
    nextMove = move;
    int vmSize = logic->numOfValidMoves(state);
    int validMoves[vmSize];
    logic->generateValidMoves(state, validMoves); // is changed by the function.

    if (logic->validMove(nextMove, validMoves, vmSize, state)) {
        board->setAllowed(false);
        state->makeMove(nextMove);
        state->printBoard();
        board->update();
        changePlayers();
        nextRound();
    }
    else {
        //std::cout << "Invalid move" << std::endl;
    }
    nextMove = -1;
}


void Game::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
