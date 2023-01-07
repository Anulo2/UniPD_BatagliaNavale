#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit {
   public:
    Support(Position iBow, Position iStern);
    std::vector<Entity> action(Position iTarget, std::vector<Unit *> iUnits);

    ~Support();
};

#endif