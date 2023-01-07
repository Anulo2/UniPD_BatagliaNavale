
#include "Submarine.h"

Submarine::Submarine(Position iBow, Position iStern) : Unit(iBow, iStern, 1, 1, 'E'){};

Entity* Submarine::action(Position iTarget, Unit* iUnits) {
    Position posA(7, 'c');
    Entity* entityA = new Entity(posA, 'S');
    return entityA;
}

Submarine::~Submarine() {
}