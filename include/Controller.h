#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>

#include "Unit.h"
#include "Entity.h"

class Controller{
    public:
        Controller();
        bool isUnit(Position iPos);
        std::vector<Unit>* getUnits();
        Unit* getUnit(Position iPos);
        std::vector<Unit*> getUnitsInRange(Position iPos, int range);
        
        void addUnit(Unit& iUnit);

    protected:
        std::vector<Unit> units;
        std::vector<Entity> enemyEntities;
};

#endif