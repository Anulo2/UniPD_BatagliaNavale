#ifndef COMPUTERVSCOMPUTER_H
#define COMPUTERVSCOMPUTER_H

#include "Battleship.h"
#include "Controller.h"
#include "Submarine.h"
#include "Support.h"

class ComputerVSComputer {
   public:
    ComputerVSComputer();  // piazza le navi di entrambi i giocatori in posizioni random

    Controller* getPlayer1();
    Controller* getPlayer2();

   protected:
    Controller player1;
    Controller player2;
};

std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a);
std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a);

#endif  // COMPUTERVSCOMPUTER_H