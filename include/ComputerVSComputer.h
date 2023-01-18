#ifndef COMPUTERVSCOMPUTER_H
#define COMPUTERVSCOMPUTER_H

#include "Battleship.h"
#include "Controller.h"
#include "Helper.h"
#include "Submarine.h"
#include "Support.h"

class ComputerVSComputer {
   public:
    ComputerVSComputer();  // piazza le navi di entrambi i giocatori in posizioni random

    Controller *getPlayer1();
    Controller *getPlayer2();
    std::vector<std::string> getLog();
    void addToLog(std::shared_ptr<Entity> obj);
    void addStringToLog(std::string iLog);
    int getStartingPlayer();

   protected:
    Controller player1;
    Controller player2;
    int selectPlayer;
    std::vector<std::string> log;
};

std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a);
std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a);

#endif  // COMPUTERVSCOMPUTER_H