#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Game.h"
class PlayerVSComputer : public Game {
   public:
    PlayerVSComputer();

   private:
    void placeComputerUnits(Controller &computer);
    void placePlayerUnits(Controller &player);
};

std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a);
std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a);

#endif  // PLAYERVSCOMPUTER_H