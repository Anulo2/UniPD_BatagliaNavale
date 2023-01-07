
#include "Support.h"

Support::Support(Position iBow, Position iStern) : Unit(iBow, iStern, 3, 3, 'S'){};

Entity* Support::action(Position iTarget, Unit* iUnits) {
    Position posA(7, 'c');
    Entity* entityA = new Entity(posA, 'S');
    return entityA;
}

Support::~Support() {
}