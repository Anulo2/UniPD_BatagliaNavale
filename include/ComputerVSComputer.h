#ifndef COMPUTERVSCOMPUTER_H
#define COMPUTERVSCOMPUTER_H

#include "Game.h"

class ComputerVSComputer : public Game {
   public:
    ComputerVSComputer();

   private:
    void placeUnitsFor(Controller &player);
    void placeInOrder(Controller &first, Controller &second);
};

std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a);
std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a);

#endif  // COMPUTERVSCOMPUTER_H