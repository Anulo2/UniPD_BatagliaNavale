#ifndef REPLAY_H
#define REPLAY_H

#include "Game.h"

class Replay : public Game {
   public:
    Replay(std::vector<std::string> in);
};

std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);

// HELPER FUNCTIONS

#endif  // REPLAY_H