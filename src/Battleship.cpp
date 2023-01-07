#include "Battleship.h"

Battleship::Battleship(const Position& iBow, const Position& iStern) : Unit(iBow, iStern, 5, 5, 'C'){};

std::vector<Entity> Battleship::action(Position iTarget, std::vector<Unit*> iUnits) {
    Position posA(7, 'c');
    Entity entityA(posA, 'S');
    std::vector<Entity> result;
    result.push_back(entityA);
    return result;
}

Battleship::~Battleship() {
}