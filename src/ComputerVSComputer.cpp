#include "ComputerVSComputer.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>  //librerie per generare posizioni casuali dove piazzare le navi
#include <iostream>
#include <random>

ComputerVSComputer::ComputerVSComputer() {  // TODO: CHECK RANDOMICITY
    std::srand(std::time(nullptr));
    bool placed;
    // int x, y, vert;
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
 
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale
            if (vert == 0) {
                 int x = rand() % 10 + 1;
            int y = rand() % 12 + 1;
                if (player1.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))) {
                    player1.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                 int x = rand() % 12 + 1;
            int y = rand() % 10 + 1;
                if (player1.checkUnitPlacement(new Battleship(Position(x, y - 2), Position(x, y + 2)))) {
                    player1.addUnit(new Battleship(Position(x, y - 2), Position(x, y + 2)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Vert\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }
    // printDefense(player1.getUnits());

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 10 + 1;
            int y = rand() % 12 + 1;
                if (player2.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))) {
                    player2.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                int x = rand() % 12 + 1;
            int y = rand() % 10 + 1;
                if (player2.checkUnitPlacement(new Battleship(Position(x, y - 2), Position(x, y + 2)))) {
                    player2.addUnit(new Battleship(Position(x, y - 2), Position(x, y + 2)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Vert\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 11 + 1;
            int y = rand() % 12 + 1;
                if (player1.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                    player1.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                int x = rand() % 12 + 1;
            int y = rand() % 11 + 1;
                if (player1.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                    player1.addUnit(new Support(Position(x, y - 1), Position(x, y + 1)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Vert\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 11 + 1;
                int y = rand() % 12 + 1;
                if (player2.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                    player2.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                int x = rand() % 12 + 1;
            int y = rand() % 11 + 1;
                if (player2.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                    player2.addUnit(new Support(Position(x, y - 1), Position(x, y + 1)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Vert\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            if (!player1.isUnit(Position(x, y))) {
                player1.addUnit(new Submarine(Position(x, y), Position(x, y)));
                placed = true;
                // std::cout << Position(x, y) << ", Horiz\n";
                // printDefense(player1.getUnits());
            } else {
                // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            if (!player2.isUnit(Position(x, y))) {
                player2.addUnit(new Submarine(Position(x, y), Position(x, y)));
                placed = true;
                // std::cout << Position(x, y) << ", Horiz\n";
                // printDefense(player1.getUnits());
            } else {
                // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }
    /*
    std::cout << player1 << "\n\n\n"
              << player2 << "\n";
              */
            /*
    int naveSelezionata = rand() % player1.getUnits().size() + 1;
    naveSelezionata = 0;
    Unit* unitBuff = player1.getUnits()[naveSelezionata];
    char type = unitBuff->getId();
    for (int i = 0; i < 10; i++) {
        bool valid = false;
        while (!valid) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            Position bufferPos(x, y);
            if (type == 'C') {
                std::vector<Unit*> bufferEnemy = {player2.getUnit(bufferPos)};

                std::vector<Entity> enemyEntities = unitBuff->action(bufferPos, bufferEnemy);

                player1.mergeEntities(enemyEntities);
                valid = true;
            } else if (type == 'S') {
                if (unitBuff->isVertical()) {
                    if (player2.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                        valid = true;
                    }
                } else {
                    if (player2.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                        valid = true;
                    }
                }
                if (valid) {
                    std::vector<Unit*> bufferUnit = player2.getUnitsInRange(bufferPos, 1);

                    std::vector<Entity> enemyEntities = unitBuff->action(bufferPos, bufferUnit);
                }

            } else if (type == 'E') {
            }
        }
    }
    */
    /*
    std::cout << "\n\n\n##################################################################\n";
    std::cout << "##################################################################\n";
    std::cout << "##################################################################\n\n\n\n";
    std::cout << player1 << "\n\n\n"
              << player2 << "\n";
              */
             /*
    naveSelezionata = rand() % player2.getUnits().size() + 1;
    naveSelezionata = 4;
    unitBuff = player2.getUnits()[naveSelezionata];
    type = unitBuff->getId();
    for (int i = 0; i < 2; i++) {
        unitBuff = player2.getUnits()[naveSelezionata+i];
        bool valid = false;
        while (!valid) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            Position bufferPos(x, y);
            if (type == 'C') {
                std::vector<Unit*> bufferEnemy = {player1.getUnit(bufferPos)};

                std::vector<Entity> enemyEntities = unitBuff->action(bufferPos, bufferEnemy);

                player2.mergeEntities(enemyEntities);
                valid = true;
            } else if (type == 'S') {
                if (unitBuff->isVertical()) {
                    if (player2.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                        valid = true;
                    }
                } else {
                    if (player2.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                        valid = true;
                    }
                }
                if (valid) {
                    std::vector<Unit*> bufferUnit = player2.getUnitsInRange(bufferPos, 1);

                    std::vector<Entity> enemyEntities = unitBuff->action(bufferPos, bufferUnit);
                }

            } else if (type == 'E') {
            }
        }


    }
    */
    /*
            std::cout << "\n\n\n##################################################################\n";
    std::cout << "##################################################################\n";
    std::cout << "##################################################################\n\n\n\n";
    std::cout << player1 << "\n\n\n"
              << player2 << "\n";
    */
  
    bool alive = true;
    int bufferCounter = 0;
    while(alive){
        std::cout << "########################################\n";
        int naveSelezionata = rand() % player1.getUnits().size() ;
        std::cout << naveSelezionata << "\n";
        //std::cout << naveSelezionata << "\n";
        Unit* unitBuff1 = player1.getUnits()[naveSelezionata];
        std::cout << unitBuff1 << "\n";
        char type = unitBuff1->getId();     
        bool valid = false;
        while (!valid) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            Position bufferPos(x, y);
            if (type == 'C') {
                std::cout << bufferPos << "\n";
                std::vector<Unit*> bufferEnemy = {player2.getUnit(bufferPos)};

                std::vector<Entity> enemyEntities = unitBuff1->action(bufferPos, bufferEnemy);

                player1.mergeEntities(enemyEntities);
                valid = true;
            } else if (type == 'S') {
                if (unitBuff1->isVertical()) {
                    Unit * buffer = new Support(Position(x, y - 1), Position(x, y + 1));
                    if (player1.checkUnitPlacement(buffer)) {
                        valid = true;
                    }
                } else {
                    Unit * buffer = new Support(Position(x - 1, y), Position(x + 1, y));
                    if (player1.checkUnitPlacement(buffer)) {
                        valid = true;
                    }
                }
                if (valid) {
                    std::cout << bufferPos << "\n";
                    std::vector<Unit*> bufferUnit = player1.getUnitsInRange(bufferPos, 1);

                    std::vector<Entity> enemyEntities = unitBuff1->action(bufferPos, bufferUnit);
                }

            } else if (type == 'E') {

                if (!player1.isUnit(Position(x,y))) {
                    valid = true;
                    std::cout << bufferPos << "\n";
                }
                
                if (valid) {
                    std::vector<Unit*> bufferUnit = player2.getUnitsInRange(bufferPos, 2);
                    std::cout << bufferUnit.size() << "\n";
                    std::vector<Entity> enemyEntities = unitBuff1->action(bufferPos, bufferUnit);
                    player1.mergeEntities(enemyEntities);
                }
            }
        }
        std::cout << player1 << "\n";

        naveSelezionata = rand() % player2.getUnits().size() ;
        std::cout << naveSelezionata << "\n";
        Unit * unitBuff2 = player2.getUnits()[naveSelezionata];
        std::cout << unitBuff2 << "\n";
        type = unitBuff2->getId();
        
        valid = false;
        while (!valid) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            Position bufferPos(x, y);
            if (type == 'C') {
                std::cout << bufferPos << "\n";
                std::vector<Unit*> bufferEnemy = {player1.getUnit(bufferPos)};

                std::vector<Entity> enemyEntities = unitBuff2->action(bufferPos, bufferEnemy);

                player2.mergeEntities(enemyEntities);
                valid = true;
            } else if (type == 'S') {
                if (unitBuff2->isVertical()) {
                    Unit * buffer = new Support(Position(x, y - 1), Position(x, y + 1));
                    if (player2.checkUnitPlacement(buffer)) {
                        valid = true;
                    }
                } else {
                    Unit * buffer = new Support(Position(x - 1, y), Position(x + 1, y));
                    if (player2.checkUnitPlacement(buffer)) {
                        valid = true;
                    }
                }
                if (valid) {
                    std::cout << bufferPos << "\n";
                    std::vector<Unit*> bufferUnit = player2.getUnitsInRange(bufferPos, 1);

                    std::vector<Entity> enemyEntities = unitBuff2->action(bufferPos, bufferUnit);
                }

            } else if (type == 'E') {

                if (!player1.isUnit(Position(x,y))) {
                    valid = true;
                    std::cout << bufferPos << "\n";
                }
                
                if (valid) {
                    std::vector<Unit*> bufferUnit = player1.getUnitsInRange(bufferPos, 2);
                    std::cout << bufferUnit.size() << "\n";
                    std::vector<Entity> enemyEntities = unitBuff2->action(bufferPos, bufferUnit);
                    player2.mergeEntities(enemyEntities);
                }
            }
        }
        
        std::cout << player2 << "\n";
        

        bufferCounter++;
        //std::cout << bufferCounter << "\n";
        if(bufferCounter==300){
            alive = false;
        }


    }
    std::cout << "\n\n\n##################################################################\n";
    std::cout << "##################################################################\n";
    std::cout << "##################################################################\n\n\n\n";
    std::cout << player1 << "\n\n\n"
              << player2 << "\n";
    
}
Controller* ComputerVSComputer::getPlayer1() {
    return &player1;
}

Controller* ComputerVSComputer::getPlayer2() {
    return &player2;
}

std::ostream& operator<<(std::ostream& os, ComputerVSComputer& a) {
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream& operator<<(std::ostream& os, ComputerVSComputer* a) {
    os << *a;
    return os;
}