// Eris Sanson

#ifndef REPLAY_H
#define REPLAY_H
#include <chrono>
#include <fstream>
#include <thread>

#include "Game.h"

class Replay : public Game {
public:
    Replay(); // costruttore

    void startGame(std::vector<std::string> inputVector); // piazza le navi nelle griglie

    bool getStartingPlayer(std::string firstPlayer);                                                                                 // getter del giocatore iniziale
    void printActionInOrder(Controller *first, Controller *second, std::vector<std::string> inputVector);                            // scrive le azioni in ordine su terminale
    void writeActionInOrder(Controller *first, Controller *second, std::vector<std::string> inputVector, std::ofstream &outputFile); // scrive le azioni in ordine su file

private:
    void placeUnitsFor(Controller &player, std::vector<std::string> inputVector);                   // piazza le navi per il giocatore dato
    void placeInOrder(Controller &first, Controller &second, std::vector<std::string> inputVector); // piazza le navi in ordine
};

// overload operatori
std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);

#endif // REPLAY_H