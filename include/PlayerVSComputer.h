#ifndef PLAYERVSCOMPUTER_H
#define PLAYERVSCOMPUTER_H

#include "Battleship.h"
#include "Controller.h"
#include "Submarine.h"
#include "Support.h"

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


//HELPER FUNCTIONS

//Return a Position from a input string
std::vector<Position> inputManipolation();

//Convert string to integer value
int stringTointeger(const std::string str);

//Function that takes a input Battleship
std::shared_ptr<Battleship> inputBattleship();

//Function that takes a input Support
std::shared_ptr<Support> inputSupport();

//Function that takes a input Submarine
std::shared_ptr<Submarine> inputSubmarine();


#endif  // PLAYERVSCOMPUTER_H