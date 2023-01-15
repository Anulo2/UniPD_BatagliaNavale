#include <iostream>

#include "Battleship.h"
#include "ComputerVSComputer.h"
#include "Controller.h"
#include "Entity.h"
#include "PlayerVSComputer.h"
#include "Position.h"
#include "Submarine.h"
#include "Support.h"
#include "Unit.h"


using namespace std;

int main(){
    /*
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
Position posD(8, 11);

std::cout << "Is inside posC:  " << battleshipA.containsPos(posC) << std::endl;

std::cout << "Is inside posD:  " << battleshipA.containsPos(posD) << std::endl;

std::vector<Unit*> units = {&battleshipA};

std::vector<Entity> entitaAzioneA = battleshipA.action(posC, units);

std::cout << "Risultato azione:  " << entitaAzioneA.at(0) << std::endl;

std::vector<Entity> entitaAzioneB = battleshipA.action(posD, units);

std::cout << "Risultato azione:  " << entitaAzioneB.at(0) << std::endl;
*/
    /*
        Controller controllerA;

        controllerA.addUnit(battleshipA);

        std::cout << "Is unit posC: " << controllerA.isUnit(posC) << std::endl;

        std::cout << "Is unit posD: " << controllerA.isUnit(posD) << std::endl;

        std::cout << "Unit at posC: " << controllerA.getUnit(posC) << std::endl;

        std::vector<Unit>* unitsController = controllerA.getUnits();

        std::cout << "Units: " << std::endl;
        */
    /*
    for (std::size_t i = 0; i < unitsController.size(); ++i) {
        std::cout << "Unit at index: " << i << ": " << unitsController[i] << std::endl;
    }

    unitsController = controllerA.getUnitsInRange(posD, 1);

    std::cout << "Units in range 2 from posD: " << std::endl;

    for (std::size_t i = 0; i < unitsController.size(); ++i) {
        std::cout << "Unit at index: " << i << ": " << unitsController[i] << std::endl;
    }
    */
    /*
     Controller controllerA;

     Battleship battleship1(Position(2, 'c'), Position(6, 'c'));
     Submarine submarine1(Position(9, 'h'));

     controllerA.addUnit(&battleship1);
     controllerA.addUnit(&submarine1);

     Controller controllerB;

     Battleship battleship2(Position(7, 'c'), Position(7, 'g'));

     Support support1(Position(7, 'H'), Position(9, 'H'));

     controllerB.addUnit(&battleship2);
     controllerB.addUnit(&support1);

     std::vector<Unit*> target = {controllerB.getUnit(Position(7, 'e'))};

     std::vector<Entity> enemyEntities = battleship1.action(Position(7, 'e'), target);

     std::vector<Unit*> controllerBUnits = controllerB.getUnits();

     std::cout << "Unità del controller B: " << std::endl;

     for (int i = 0; i < controllerBUnits.size(); i++) {
         std::cout << controllerBUnits[i] << std::endl;
     }

     std::vector<Unit*> bufferUnits = controllerB.getUnitsInRange(Position(9, 'h'), 2);

     std::vector<Entity> entitiesBuffer = submarine1.action(Position(9, 'h'), bufferUnits);

     enemyEntities.insert(enemyEntities.end(), entitiesBuffer.begin(), entitiesBuffer.end());

     // entities griglia d'attacco
     for (int i = 0; i < enemyEntities.size(); i++) {
         std::cout << enemyEntities[i] << std::endl;
     }

     bufferUnits = controllerB.getUnitsInRange(Position(8, 'h'), 1);

     entitiesBuffer = support1.action(Position(8, 'h'), bufferUnits);

     std::cout << "unità player 2 \n";
     for (int i = 0; i < controllerBUnits.size(); i++) {
         std::cout << controllerBUnits[i] << std::endl;
     }

     std::cout << "unità player 1 \n";
     for (int i = 0; i < controllerA.getUnits().size(); i++) {
         std::cout << controllerA.getUnits()[i] << std::endl;
     }
     */
    /*std::cout << "\n\n\n";
    std::cout << "######   COMPUTER VS COMPUTER   ######\n";
    ComputerVSComputer b;
    std::cout << b << std::endl;

      
    std::cout << "\n\n\n";
    std::cout<<"######################################\n";
    std::cout<<"########   START INPUT PLVSPC   ######\n";
    std::cout<<"######################################\n";
*/
    ComputerVSComputer a;
    
    //PlayerVSComputer a;
    std::cout<<"######################################\n";
    std::cout<<"########   PLAYER VS COMPUTER   ######\n";
    std::cout<<"######################################\n";
    int i = 0;
    while(true){
        i++;
        inputHelper::randomAction(a.getPlayer1(), a.getPlayer2());
        inputHelper::randomAction(a.getPlayer2(), a.getPlayer1());
        std::cout << "Turno: " << i << "\n";
        std::cout << "Player1\n" << a.getPlayer1() << "\n";
        std::cout << "Player2\n"<< a.getPlayer2() << "\n";
    
        if (a.getPlayer1()->isDead()){
            std::cout << "Hai Perso!";
            break;
        }
        if (a.getPlayer2()->isDead()){
            std::cout << "Hai vinto!";
            break;
        }
    }

    

      
        /*for(int i=0; i<5; i++){

        std::cout<<randomBattleship()<<"\n";
        std::cout<<randomSupport()<<"\n";
        std::cout<<randomSubmarine()<<"\n";
    }*/



    /*
    std::cout << "NAVI RANDOM PLAYER1 \n";
    Controller* play1 = a.getPlayer1();
    std::cout << play1->getUnits().size() << std::endl;  // riconosce correttamente 8 unità

    for (int i = 0; i < play1->getUnits().size(); i++) {
        std::cout << play1->getUnits()[i] << std::endl;
    }

    std::cout << "NAVI RANDOM PLAYER2 \n";
    Controller* play2 = a.getPlayer2();
    std::cout << play2->getUnits().size() << std::endl;  // riconosce correttamente 8 unità

    for (int i = 0; i < play2->getUnits().size(); i++) {
        std::cout << play2->getUnits()[i] << std::endl;
    }*/
    /*
    Controller player1;
    Controller player2;

    player1.addUnit(new Battleship(Position(3, 'i'), Position(7, 'i')));
    player1.addUnit(new Battleship(Position(3, 'd'), Position(3, 'h')));
    player1.addUnit(new Battleship(Position(4, 'E'), Position(8, 'E')));
    player1.addUnit(new Support(Position(4, 'h'), Position(6, 'H')));
    player1.addUnit(new Support(Position(4, 'f'), Position(6, 'f')));
    player1.addUnit(new Support(Position(10, 'h'), Position(10, 'f')));
    player1.addUnit(new Submarine(Position(11, 12), Position(11, 12)));
    player1.addUnit(new Submarine(Position(5, 7), Position(5, 7)));

    player2.addUnit(new Battleship(Position(3, 'i'), Position(7, 'i')));
    player2.addUnit(new Battleship(Position(3, 'd'), Position(3, 'H')));
    player2.addUnit(new Battleship(Position(4, 'e'), Position(8, 'E')));
    player2.addUnit(new Support(Position(4, 'h'), Position(6, 'H')));
    player2.addUnit(new Support(Position(4, 'f'), Position(6, 'f')));
    player2.addUnit(new Support(Position(10, 'h'), Position(10, 'f')));
    player2.addUnit(new Submarine(Position(11, 12), Position(11, 12)));
    player2.addUnit(new Submarine(Position(5, 7), Position(5, 7)));
    */
    /*
    ##################################
    #             BATTLESHIP         #
    ##################################
    */
    /*
     {
         std::vector<Unit *> buffer = {player2.getUnit(Position(6, 'e'))};
         std::vector<Entity> resultEntities = player1.getUnits()[0]->action(Position(7, 'e'), buffer);
         player1.mergeEntities(resultEntities);
     }
     {
         std::vector<Unit *> buffer = {player1.getUnit(Position(6, 'e'))};
         std::vector<Entity> resultEntities = player2.getUnits()[0]->action(Position(7, 'e'), buffer);
         player2.mergeEntities(resultEntities);
     }
     {
         std::vector<Unit *> buffer = {player2.getUnit(Position(4, 'h'))};
         std::vector<Entity> resultEntities = player1.getUnits()[0]->action(Position(4, 'h'), buffer);
         player1.mergeEntities(resultEntities);
     }
     {
         std::vector<Unit *> buffer = {player1.getUnit(Position(4, 'h'))};
         std::vector<Entity> resultEntities = player2.getUnits()[0]->action(Position(4, 'h'), buffer);
         player2.mergeEntities(resultEntities);
     }
     {
         std::vector<Unit *> buffer = {player2.getUnit(Position(10, 'g'))};
         std::vector<Entity> resultEntities = player1.getUnits()[0]->action(Position(10, 'f'), buffer);
         player1.mergeEntities(resultEntities);
     }
     {
         std::vector<Unit *> buffer = {player1.getUnit(Position(10, 'g'))};
         std::vector<Entity> resultEntities = player2.getUnits()[0]->action(Position(10, 'f'), buffer);
         player2.mergeEntities(resultEntities);
     }
     */
    /*
    ##################################
    #              SUPPORT           #
    ##################################
    */
    /*
     {
         std::vector<Unit *> buffer = player1.getUnitsInRange(Position(6, 'F'), 1);
         std::vector<Entity> resultEntities = player1.getUnits()[4]->action(Position(6, 'F'), buffer);
         player1.mergeEntities(resultEntities);
     }
     {
         std::vector<Unit *> buffer = player2.getUnitsInRange(Position(6, 'F'), 1);
         std::vector<Entity> resultEntities = player2.getUnits()[4]->action(Position(6, 'F'), buffer);
         player2.mergeEntities(resultEntities);
     }
     */
    /*
    ##################################
    #             SUBMARINE          #
    ##################################
    */
    /*

     {
         std::vector<Unit *> buffer = player2.getUnitsInRange(Position(4, 'g'), 2);
         std::vector<Entity> resultEntities = player1.getUnits()[7]->action(Position(4, 'g'), buffer);
         player1.mergeEntities(resultEntities);
     }

     {
         std::vector<Unit *> buffer = player1.getUnitsInRange(Position(4, 'g'), 2);
         std::vector<Entity> resultEntities = player2.getUnits()[7]->action(Position(4, 'g'), buffer);
         player2.mergeEntities(resultEntities);
     }

     std::cout << player1 << "\n";
     std::cout << player2 << "\n";
     */

    return 0;
}

/*
N # # # # # # # # # # # #
M # # # # # # # # # # # #
L # # # # # # # # # # # #
I # # # # # # # # # # # #
H # # # # # # # # E # # #
G # # # # # # # # # # # #
F # # # # # # # # # # # #
E # # # # # # # # # # # #
D # # # # # # # # # # # #
C # C C C C C # # # # # #
B # # # # # # # # # # # #
A # # # # # # # # # # # #
  1 2 3 4 5 6 7 8 9 101112

N # # # # # # # # # # # #
M # # # # # # # # # # # #
L # # # # # # # # # # # #
I # # # # # # # # # # # #
H # # # # # # Y Y Y # # #
G # # # # # # Y # # # # #
F # # # # # # Y # # # # #
E # # # # # # X # # # # #
D # # # # # # # # # # # #
C # # # # # # # # # # # #
B # # # # # # # # # # # #
A # # # # # # # # # # # #
  1 2 3 4 5 6 7 8 9 101112

N # # # # # # # # # # # #
M # # # # # # # # # # # #
L # # # # # # # # # # # #
I # # # # # # # # # # # #
H # # # # # # S S S # # #
G # # # # # # C # # # # #
F # # # # # # C # # # # #
E # # # # # # C # # # # #
D # # # # # # C # # # # #
C # # # # # # C # # # # #
B # # # # # # # # # # # #
A # # # # # # # # # # # #
  1 2 3 4 5 6 7 8 9 101112





N # # # # # # # # # # # #
M # # # # # # # # # # # #
L # # # # # # # # # # # #
I # # # # # # # # # # # #
H # # # # # # # # # # # #
G # # # # S # # # # # # #
F # # # C C C C C # # # #
E # # # # S # # # # # # #
D # # # # # # # # # # # #
C # # # # # # # # # # # #
B # # # # # # # # # # # #
A # # # # # # # # # # # #
  1 2 3 4 5 6 7 8 9 101112


*/