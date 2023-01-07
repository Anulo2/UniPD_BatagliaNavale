
#include "Support.h"

Support::Support(Position iBow, Position iStern) : Unit(iBow, iStern, 3, 3, 'S'){};

std::vector<Entity> Support::action(Position iTarget, std::vector<Unit *> iUnits) {
    Position posA(7, 'c');
    Entity entityA(posA, 'S');
    std::vector<Entity> result = {entityA};
    return result;
}

Support::~Support() {
}