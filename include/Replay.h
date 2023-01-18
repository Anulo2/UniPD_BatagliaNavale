// Eris Sanson

#ifndef REPLAY_H
#define REPLAY_H

#include "Game.h"

class Replay : public Game {
   public:
    Replay(std::vector<std::string> in);

   private:
    void placeUnitsFor(Controller &player, std::vector<std::string> inVect);
    void placeInOrder(Controller &first, Controller &second, std::vector<std::string> inVect);
};

std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);

// HELPER FUNCTIONS

#endif  // REPLAY_H