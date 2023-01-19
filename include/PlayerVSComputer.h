// Leonardo Canello

#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Game.h"
class PlayerVSComputer : public Game {
public:
    PlayerVSComputer(); // costruttore di default

    void startGame(); // piazza unità e inizia gioco (virtuale di game)

private:
    void placeComputerUnits(Controller &computer); // piazza unità del pc
    void placePlayerUnits(Controller &player);     // piazza unità del giocatore umano
};

// overload operatori
std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a);
std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a);

#endif // PLAYERVSCOMPUTER_H