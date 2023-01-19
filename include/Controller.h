// Leonardo Canello

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "Unit.h"

class Controller {
public:
    // costruttore di default
    Controller();

    // true se c'è una nave in iPos
    bool isUnit(const Position &iPos) const;

    // getter di tutte le navi
    std::vector<std::shared_ptr<Unit>> getUnits();

    // getter nave in iPos
    std::shared_ptr<Unit> getUnit(const Position &iPos);

    // getter navi nel range dato
    std::vector<std::shared_ptr<Unit>> getUnitsInRange(const Position &iPos, const int &range);

    // controlli piazzamento nave
    bool checkUnitPlacement(std::shared_ptr<Unit> originalUnit, std::shared_ptr<Unit> iUnit);

    // aggiunge una nave
    void addUnit(std::shared_ptr<Unit> iUnit);

    // rimuove unità abbattute
    bool removeDeadUnits();

    // print griglia difesa
    void printDefense(std::ostream &os);

    // print griglia attacco
    void printAttack(std::ostream &os);

    // print entrambe le griglie
    void print(std::ostream &os) const;

    // merge delle entità
    void mergeEntities(std::vector<std::shared_ptr<Entity>> iEnemyEntities);

    // pulisce griglia d'attacco
    void clearAttackGrid(const char &x);

    // restituisce se tutte le unità sono state abbattute
    bool isDead();

    // distruttore
    ~Controller();

protected:
    std::vector<std::shared_ptr<Unit>> units;
    std::vector<std::shared_ptr<Entity>> enemyEntities;
    Entity defaultEntity;
    std::shared_ptr<Entity> enemyEntitiesMatrix[12][12];
    bool dead = false;
};
// overload operatori
std::ostream &operator<<(std::ostream &os, const Controller &a);
std::ostream &operator<<(std::ostream &os, const Controller *a);

#endif