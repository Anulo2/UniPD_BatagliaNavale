// Leonardo Canello

#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Game.h"
class PlayerVSComputer : public Game {
   public:
    // costruttore di default
    PlayerVSComputer();
    // piazza unità e inizia gioco (virtuale di game)
    void startGame();

   private:
    // piazza unità del pc
    void placeComputerUnits(Controller &computer);

    // piazza unità del giocatore umano
    void placePlayerUnits(Controller &player);
};

// overload operatori
std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a);
std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a);

#endif  // PLAYERVSCOMPUTER_H