// Enrico Zanoni

#ifndef COMPUTERVSCOMPUTER_H
#define COMPUTERVSCOMPUTER_H

#include "Game.h"

class ComputerVSComputer : public Game {
public:
    ComputerVSComputer(); // costruttore di default

    void startGame(); // piazza unità e inizia gioco (virtuale di game)

private:
    void placeUnitsFor(Controller &player);                   // piazza unità al controller dato
    void placeInOrder(Controller &first, Controller &second); // piazza le unità in ordine ai due controller
};

// overload operatori
std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a);
std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a);

#endif // COMPUTERVSCOMPUTER_H