#include "Battleship.h"

Battleship::Battleship(Position iBow, Position iStern) : Unit(iBow, iStern) {};


Entity* Battleship::action(Position iTarget, Unit * iUnits){
    Position posA(7, 'c');
    Entity entityA(posA, 'S');
    return &entityA;
}