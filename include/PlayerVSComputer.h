#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Battleship.h"
#include "Controller.h"
#include "Submarine.h"
#include "Support.h"
#include "inputHelper.h"


class PlayerVSComputer {
   public:
    PlayerVSComputer();  

    Controller* getPlayer1();
    Controller* getPlayer2();
    

protected:
    Controller player1;
    Controller player2;
};

std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a);
std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a);


#endif  // PLAYERVSCOMPUTER_H