#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Unit.h"

class Battleship : public Unit{

    public:
        Battleship(Position iBow, Position iStern);
        Entity * action(Position iTarget, Unit * iUnits);

    private:
        static const int dimension=5;
        int armor = 5;
        static const char id = 'C';
};

#endif