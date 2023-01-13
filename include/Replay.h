#ifndef REPLAY_H
#define REPLAY_H

#include <string>

#include "Battleship.h"
#include "Controller.h"
#include "Submarine.h"
#include "Support.h"

class Replay {
   public:
    Replay(std::vector<std::string> in);  

    Controller* getPlayer1();
    Controller* getPlayer2();

   protected:
    Controller player1;
    Controller player2;
};
std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);


//HELPER FUNCTIONS

//Takes a string as input from a file
std::vector<Position> inputString(const std::string in);

//Convert string to integer value
int stringTointeger(const std::string str);

//Function that takes a input Battleship
std::shared_ptr<Battleship> inputBattleship(const std::string in);

//Function that takes a input Support
std::shared_ptr<Support> inputSupport(const std::string in);

//Function that takes a input Submarine
std::shared_ptr<Submarine> inputSubmarine(const std::string in);


#endif  // REPLAY_H