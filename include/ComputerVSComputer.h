#ifndef COMPUTERVSCOMPUTER_H
#define COMPUTERVSCOMPUTER_H


#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"
#include "Controller.h"

class ComputerVSComputer{
    public:
        ComputerVSComputer(); //piazza le navi di entrambi i giocatori in posizioni random


    protected:
        Controller player1;
        Controller player2;
};

#endif //COMPUTERVSCOMPUTER_H