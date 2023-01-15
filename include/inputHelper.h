#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <random>
#include <iostream>

#include "Controller.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Support.h"

namespace inputHelper{
    void writeLog(std::ostream &os, std::vector<std::string> log);

    std::string addContentToLog(std::shared_ptr<Unit> obj);

    std::string addContentToLog(Position target, std::shared_ptr<Unit> obj);

    std::string logToString(std::vector<std::string> log);

    

    //Return String from player input stream
    std::string getPlayerInput(std::istream& is);
    
    //return a position from a input string
    std::vector<Position> inputString(std::string in);

    //Convert string to integer value
    int stringTointeger(const std::string str);

    //Function that takes a input String and return a new Battleship
    std::shared_ptr<Battleship> inputBattleship(std::string in);

    //Function that takes a input String and return a new Support
    std::shared_ptr<Support> inputSupport(std::string in);

    //Function that takes a input String and return a new Submarine
    std::shared_ptr<Submarine> inputSubmarine(std::string in);

    //To get a random Battleship
    std::shared_ptr<Unit> randomBattleship();

    //To get a random Support
    std::shared_ptr<Unit> randomSupport();

    //To get a random Submarine
    std::shared_ptr<Unit> randomSubmarine();

    //Random action by player1 + merge entity
    std::string randomAction(Controller* player1, Controller* player2);

    //Gestisce l'acquisizione dell'azione del player
    std::string handlePlayerAction(Controller* player1, Controller* player2);

}

#endif //INPUTHELPER_H