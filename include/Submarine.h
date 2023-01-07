#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit {
   public:
    Submarine(Position iBow, Position iStern);
    Entity* action(Position iTarget, Unit* iUnits);

    ~Submarine();

   private:
    static const int dimension = 1;
    int armor = 1;
    static const char id = 'E';
};

#endif