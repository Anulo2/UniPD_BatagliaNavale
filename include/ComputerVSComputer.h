// Enrico Zanoni

#ifndef COMPUTERVSCOMPUTER_H
#define COMPUTERVSCOMPUTER_H

#include "Game.h"

class ComputerVSComputer : public Game {
public:
    // costruttore di default
    ComputerVSComputer();

    // piazza unità e inizia gioco (virtuale di game)
    void startGame();

private:
    // piazza unità al controller dato

    void placeUnitsFor(Controller &player);

    // piazza le unità in ordine ai due controller
    void placeInOrder(Controller &first, Controller &second);
};

// overload operatori
std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a);
std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a);

#endif // COMPUTERVSCOMPUTER_H