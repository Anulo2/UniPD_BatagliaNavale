#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Game.h"
class PlayerVSComputer : public Game {
   public:
    PlayerVSComputer();
};

std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a);
std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a);

#endif  // PLAYERVSCOMPUTER_H