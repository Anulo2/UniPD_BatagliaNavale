// Leonardo Canello

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "Unit.h"

class Controller {
public:
    Controller();                                                                             // csotruttore di default
    bool isUnit(Position iPos);                                                               // true se c'è una nave in iPos
    std::vector<std::shared_ptr<Unit>> getUnits();                                            // getter di tutte le navi
    std::shared_ptr<Unit> getUnit(Position iPos);                                             // getter nave in iPos
    std::vector<std::shared_ptr<Unit>> getUnitsInRange(Position iPos, int range);             // getter navi nel range dato
    bool checkUnitPlacement(std::shared_ptr<Unit> originalUnit, std::shared_ptr<Unit> iUnit); // controlli piazzamento nave

    void addUnit(std::shared_ptr<Unit> iUnit); // aggiunge una nave
    bool removeDeadUnits();                    // rimuove unità abbattute

    void printDefense(std::ostream &os);                                     // print griglia difesa
    void printAttack(std::ostream &os);                                      // print griglia attacco
    void print(std::ostream &os);                                            // print entrambe le griglie
    void mergeEntities(std::vector<std::shared_ptr<Entity>> iEnemyEntities); // merge delle entità

    void clearAttackGrid(const char x); // pulisce griglia d'attacco

    bool isDead(); // restituisce se tutte le unità sono state abbattute
    ~Controller(); // distruttore

protected:
    std::vector<std::shared_ptr<Unit>> units;
    std::vector<std::shared_ptr<Entity>> enemyEntities;
    Entity defaultEntity;
    std::shared_ptr<Entity> enemyEntitiesMatrix[12][12];
    bool dead = false;
};
// overload operatori
std::ostream &operator<<(std::ostream &os, Controller &a);
std::ostream &operator<<(std::ostream &os, Controller *a);

#endif