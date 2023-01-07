
#include "Submarine.h"

Submarine::Submarine(Position iBow, Position iStern) : Unit(iBow, iStern, 1, 1, 'E'){};

std::vector<Entity> Submarine::action(Position iTarget, std::vector<Unit *> iUnits) {
    Position posA(7, 'c');
    Entity entityA(posA, 'S');
    std::vector<Entity> result = {entityA};
    return result;
}

Submarine::~Submarine() {
}