#include "Battleship.h"

Battleship::Battleship(const Position& iBow, const Position& iStern) : Unit(iBow, iStern, 5, 5, 'C'){};

Entity* Battleship::action(Position iTarget, Unit* iUnits) {
    Position posA(7, 'c');
    Entity* entityA = new Entity(posA, 'S');
    return entityA;
}

Battleship::~Battleship() {
}