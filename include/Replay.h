#ifndef REPLAY_H
#define REPLAY_H

#include "Battleship.h"
#include "Controller.h"
#include "Helper.h"
#include "Submarine.h"
#include "Support.h"

class Replay {
   public:
    Replay(std::vector<std::string> in);

    Controller *getPlayer1();
    Controller *getPlayer2();
    std::vector<std::string> getLog();
    void addStringToLog(std::string iLog);

   protected:
    Controller player1;
    Controller player2;
    std::vector<std::string> log;
};

std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);

// HELPER FUNCTIONS

#endif  // REPLAY_H