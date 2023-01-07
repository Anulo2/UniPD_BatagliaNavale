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

    Battleship battleshipA(posA, posB);

    std::cout << "middle: " << battleshipA.getMiddle() << std::endl;

    std::cout << "vertical? " << battleshipA.isVertical() << std::endl;

    std::cout << "id:  " << battleshipA.getId() << std::endl;

    std::cout << "Bow:  " << battleshipA.getBow() << std::endl;

    std::cout << "Stern:  " << battleshipA.getStern() << std::endl;

    Position posC(8, 'n');
    Position posD(8, 10);

    std::cout << "Is inside posC:  " << battleshipA.isInside(posC) << std::endl;

    std::cout << "Is inside posD:  " << battleshipA.isInside(posD) << std::endl;

    return 0;
}