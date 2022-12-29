#include <iostream>

#include "Controller.h"
#include "Entity.h"
#include "Battleship.h"
#include "Support.h"
#include "Submarine.h"
#include "Unit.h"
#include "Position.h"
#include "PlayerVSComputer.h"
#include "ComputerVSComputer.h"

using namespace std;

int main(){

    Position posA(7, 'c');
    Position posB(7, 7);
    std::cout << posA.getY();
    std::cout << posA.getIntY();
    std::cout << posA.getX();
    std::cout << posB.getY();
    std::cout << posB.getIntY();
    std::cout << posB.getX();

    Entity entityA(posA, 'S');

    return 0;
}