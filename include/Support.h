#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit {
   public:
    Support(Position iBow, Position iStern);
    Entity* action(Position iTarget, Unit* iUnits);

    ~Support();

   private:
    static const int dimension = 3;
    int armor = 3;
    static const char id = 'S';
};

#endif