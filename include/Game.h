// Eris Sanson

#ifndef GAME_H
#define GAME_H

#include <ostream>

#include "Helper.h"

class Game {
   public:
    Game();

    Controller *getPlayer1();
    Controller *getPlayer2();

    virtual void startGame();

    std::vector<std::string> getLog();
    void addToLog(std::shared_ptr<Entity> obj);
    void addStringToLog(std::string iLog);
    int getStartingPlayer();

    bool placeUnit(Controller &player, Helper::unitType unitType);
    void placeUnit(Controller &player, Helper::unitType unitType, std::string inString);
    void placeUnits(Controller &player, Helper::unitType unitType, int quantity);

   protected:
    Controller player1;
    Controller player2;
    int selectPlayer;
    std::vector<std::string> log;
};
std::ostream &operator<<(std::ostream &os, Entity &a);
std::ostream &operator<<(std::ostream &os, Entity *a);
bool operator==(Entity a, Entity b);
bool operator!=(Entity a, Entity b);
#endif