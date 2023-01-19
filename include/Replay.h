// Eris Sanson

#ifndef REPLAY_H
#define REPLAY_H
#include <chrono>
#include <fstream>
#include <thread>

#include "Game.h"

class Replay : public Game {
   public:
    Replay(std::vector<std::string> inputVector);
    bool getStartingPlayer(std::string firstPlayer);
    void printActionInOrder(Controller *first, Controller *second, std::vector<std::string> inputVector);
    void writeActionInOrder(Controller *first, Controller *second, std::vector<std::string> inputVector, std::ofstream &outputFile);

   private:
    void placeUnitsFor(Controller &player, std::vector<std::string> inputVector);
    void placeInOrder(Controller &first, Controller &second, std::vector<std::string> inputVector);
};
std::ostream &operator<<(std::ostream &os, Replay &a);
std::ostream &operator<<(std::ostream &os, Replay *a);

// HELPER FUNCTIONS

#endif  // REPLAY_H