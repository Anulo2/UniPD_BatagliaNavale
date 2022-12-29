
#include "Support.h"

Support::Support(Position iBow, Position iStern) : Unit(iBow, iStern) {};


Entity* Support::action(Position iTarget, Unit * iUnits){
    Position posA(7, 'c');
    Entity entityA(posA, 'S');
    return &entityA;
}