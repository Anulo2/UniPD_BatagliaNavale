#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>

#include "Entity.h"
#include "Unit.h"

class Controller {
   public:
    Controller();
    bool isUnit(Position iPos);
    std::vector<Unit *> getUnits();
    Unit *getUnit(Position iPos);
    std::vector<Unit *> getUnitsInRange(Position iPos, int range);
    bool checkUnitPlacement(Unit *iUnit);  // TODO: controllare se ci sono gia unità nelle caselle di iUnit

    void addUnit(Unit *iUnit);
    void removeDeadUnits();
    // void addUnit(Unit iUnit);
    void printDefense(std::ostream &os);
    void printAttack(std::ostream &os);
    void print(std::ostream &os);
    void mergeEntities(std::vector<Entity> iEnemyEntities);
    ~Controller();

   protected:
    std::vector<Unit *> units = {};
    std::vector<Entity> enemyEntities = {};
    Entity defaultEntity;
    Entity *enemyEntitiesMatrix[12][12];
};
std::ostream &operator<<(std::ostream &os, Controller &a);
std::ostream &operator<<(std::ostream &os, Controller *a);

bool operator==(Controller a, Controller b);
bool operator!=(Controller a, Controller b);

#endif