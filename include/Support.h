// Enrico Zanoni

#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit {
   public:
    Support(Position iBow, Position iStern);
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits);

    ~Support();
};

#endif