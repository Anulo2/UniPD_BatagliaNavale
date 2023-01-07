#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Unit.h"

class Battleship : public Unit {
   public:
    Battleship(const Position& iBow, const Position& iStern);
    Entity* action(Position iTarget, Unit* iUnits);
    ~Battleship();
};

#endif