#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Unit.h"

class Battleship : public Unit {
   public:
    Battleship(const Position& iBow, const Position& iStern);

    std::vector<Entity> action(Position iTarget, std::vector<Unit*> iUnits);
    ~Battleship();
};

#endif