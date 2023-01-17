#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "Unit.h"

class Controller {
   public:
    Controller();
    bool isUnit(Position iPos);
    std::vector<std::shared_ptr<Unit>> getUnits();
    std::shared_ptr<Unit> getUnit(Position iPos);
    std::vector<std::shared_ptr<Unit>> getUnitsInRange(Position iPos, int range);
    bool checkUnitPlacement(std::shared_ptr<Unit> originalUnit, std::shared_ptr<Unit> iUnit);

    void addUnit(std::shared_ptr<Unit> iUnit);
    bool removeDeadUnits();

    void printDefense(std::ostream &os);
    void printAttack(std::ostream &os);
    void print(std::ostream &os);
    void mergeEntities(std::vector<std::shared_ptr<Entity>> iEnemyEntities);

    void clearAttackGrid(const char x);

    bool isDead();
    ~Controller();

   protected:
    // std::vector<Unit *> units = {};
    std::vector<std::shared_ptr<Unit>> units;
    std::vector<std::shared_ptr<Entity>> enemyEntities;
    Entity defaultEntity;
    std::shared_ptr<Entity> enemyEntitiesMatrix[12][12];
    bool dead = false;
};
std::ostream &operator<<(std::ostream &os, Controller &a);
std::ostream &operator<<(std::ostream &os, Controller *a);

#endif