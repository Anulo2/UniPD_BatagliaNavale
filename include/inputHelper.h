#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <random>
#include <iostream>

#include "Controller.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

namespace inputHelper{

    //return a position from a input string
    std::vector<Position> inputString(std::string in);

    // Return a Position from the input stream
    std::vector<Position> inputManipolation(std::istream& is);

    //Convert string to integer value
    int stringTointeger(const std::string str);

    //Function that takes a input Battleship
    std::shared_ptr<Battleship> inputBattleship(std::istream& is);

    //Function that takes a input Support
    std::shared_ptr<Support> inputSupport(std::istream& is);

    //Function that takes a input Submarine
    std::shared_ptr<Submarine> inputSubmarine(std::istream& is);



    //Function that takes a input Battleship
    std::shared_ptr<Battleship> inputBattleship(std::string in);

    //Function that takes a input Support
    std::shared_ptr<Support> inputSupport(std::string in);

    //Function that takes a input Submarine
    std::shared_ptr<Submarine> inputSubmarine(std::string in);



    //To get a random Battleship
    std::shared_ptr<Unit> randomBattleship();

    //To get a random Support
    std::shared_ptr<Unit> randomSupport();

    //To get a random Submarine
    std::shared_ptr<Unit> randomSubmarine();

}

#endif //INPUTHELPER_H