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

    Position posA(7, 'n');
    Position posB(7, 11);

    std::cout <<"A get y: " << posA.getY() << std::endl;
    
    std::cout <<"A get inty: " << posA.getIntY() << std::endl;
    
    std::cout << "A get X: " <<posA.getX() << std::endl;
    
    std::cout << "B get y: " <<posB.getY() << std::endl;
    
    std::cout << "B get inty: " <<posB.getIntY() << std::endl;
    
    std::cout << "B get x: " <<posB.getX() << std::endl;

    Battleship prova(posA, posB);
    return 0;
}