#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit {
   public:
    Support(Position iBow, Position iStern);
    Entity* action(Position iTarget, Unit* iUnits);

    ~Support();
};

#endif