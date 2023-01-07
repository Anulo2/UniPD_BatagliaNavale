#include <iostream>

#include "Battleship.h"
// #include "ComputerVSComputer.h"
// #include "Controller.h"
#include "Entity.h"
// #include "PlayerVSComputer.h"
#include "Position.h"
#include "Submarine.h"
#include "Support.h"
#include "Unit.h"

using namespace std;

int main() {
    Position posA(7, 'n');
    Position posB(12, 12);

    std::cout << "A get y: " << posA.getY() << std::endl;

    std::cout << "A get inty: " << posA.getIntY() << std::endl;

    std::cout << "A get X: " << posA.getX() << std::endl;

    std::cout << "B get y: " << posB.getY() << std::endl;

    std::cout << "B get inty: " << posB.getIntY() << std::endl;

    std::cout << "B get x: " << posB.getX() << std::endl;

    Entity entityA(posA, 'X');

    std::cout << "A getPos: " << entityA.getPos() << std::endl;

    std::cout << "a getId: " << entityA.getId() << std::endl;

    Unit *unitA = new Battleship(posA, posB);

    delete unitA;

    return 0;
}