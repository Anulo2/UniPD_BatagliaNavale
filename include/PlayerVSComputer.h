#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Battleship.h"
#include "Controller.h"
#include "Helper.h"
#include "Submarine.h"
#include "Support.h"

class PlayerVSComputer {
   public:
    PlayerVSComputer();

    Controller *getPlayer1();
    Controller *getPlayer2();
    std::vector<std::string> getLog();
    void addToLog(std::shared_ptr<Unit> obj);
    void addStringToLog(std::string iLog);
    int getStartingPlayer();

   protected:
    Controller player1;
    Controller player2;
    int selectPlayer;
    std::vector<std::string> log;
};

std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a);
std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a);

#endif  // PLAYERVSCOMPUTER_H