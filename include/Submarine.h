#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit {
   public:
    Submarine(Position iBow, Position iStern);
    Submarine(Position iPos);
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<Unit *> iUnits);

    ~Submarine();
};

#endif