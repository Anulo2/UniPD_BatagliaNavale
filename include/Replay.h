// Eris Sanson

#ifndef REPLAY_H
#define REPLAY_H
#include <chrono>
#include <fstream>
#include <thread>

#include "Game.h"

class Replay : public Game {
   public:
    // costruttore
    Replay();

    // piazza le navi nelle griglie
    void startGame(std::vector<std::string> inputVector);

    // getter del giocatore iniziale
    bool getStartingPlayer(std::string firstPlayer);

    // scrive le azioni in ordine su terminale
    void printActionInOrder(Controller *first, Controller *second, std::vector<std::string> inputVector);

    // scrive le azioni in ordine su file
    void writeActionInOrder(Controller *first, Controller *second, std::vector<std::string> inputVector, std::ofstream &outputFile);

   private:
    // piazza le navi per il giocatore dato
    void placeUnitsFor(Controller &player, std::vector<std::string> inputVector);

    // piazza le navi in ordine
    void placeInOrder(Controller &first, Controller &second, std::vector<std::string> inputVector);
};

// overload operatori
std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);

#endif  // REPLAY_H