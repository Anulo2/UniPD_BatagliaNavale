#include "ComputerVSComputer.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>  //librerie per generare posizioni casuali dove piazzare le navi
#include <iostream>
#include <random>

ComputerVSComputer::ComputerVSComputer() {  // TODO: CHECK RANDOMICITY
    std::srand(std::time(nullptr));
    bool placed;
    //int x, y, vert;
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale
            if (vert == 0) {
                if(player1.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))){
                    player1.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Horiz\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                if(player1.checkUnitPlacement(new Battleship(Position(x , y-2), Position(x, y+2)))){
                    player1.addUnit(new Battleship(Position(x, y-2), Position(x, y+2)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Vert\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        //std::cout << "Placed Battleship Player1!\n";
    }
    //printDefense(player1.getUnits());
    
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                if(player2.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))){
                    player2.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Horiz\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                if(player2.checkUnitPlacement(new Battleship(Position(x , y-2), Position(x, y+2)))){
                    player2.addUnit(new Battleship(Position(x, y-2), Position(x, y+2)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Vert\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        //std::cout << "Placed Battleship Player1!\n";
    }
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 11 + 1;
            int y = rand() % 11 + 1;
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                if(player1.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))){
                    player1.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Horiz\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                if(player1.checkUnitPlacement(new Support(Position(x , y-1), Position(x, y+1)))){
                    player1.addUnit(new Support(Position(x, y-1), Position(x, y+1)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Vert\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        //std::cout << "Placed Battleship Player1!\n";
    }
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 11 + 1;
            int y = rand() % 11 + 1;
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                if(player2.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))){
                    player2.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Horiz\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                if(player2.checkUnitPlacement(new Support(Position(x , y-1), Position(x, y+1)))){
                    player2.addUnit(new Support(Position(x, y-1), Position(x, y+1)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Vert\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }

        //std::cout << "Placed Battleship Player1!\n";
    }

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
                if (!player1.isUnit(Position(x , y))){
                    player1.addUnit(new Submarine(Position(x , y), Position(x , y)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Horiz\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
        }

        //std::cout << "Placed Battleship Player1!\n";
    }
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
                if (!player2.isUnit(Position(x , y))){
                    player2.addUnit(new Submarine(Position(x , y), Position(x , y)));
                    placed = true;
                    //std::cout << Position(x, y) << ", Horiz\n";
                    //printDefense(player1.getUnits());
                } else {
                    //std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
        }

        //std::cout << "Placed Battleship Player1!\n";
    }
    std::cout << player1 << "\n";
    std::cout << player2;
    int naveSelezionata = rand() % player1.getUnits().size() +1;
    naveSelezionata = 0;
    Unit * battleshipBuff = player1.getUnits().at(naveSelezionata);
    char type = battleshipBuff->getId();
    
    bool valid=false;
    while(!valid){
        int x = rand() % 12 + 1;
        int y = rand() % 12 + 1;
        Position bufferPos(x,y);
        if (type == 'C'){
            
            //Unit * enemyUnit = player2.getUnit(Position(x, y));
            //Battleship* battleshipBuff = (Battleship)player1.getUnits().at(naveSelezionata);
            std::vector<Unit *> bufferEnemy = {player2.getUnit(bufferPos)};
            std::cout<<"here\n";
            std::vector<Entity> enemyEntities = battleshipBuff->action(bufferPos, bufferEnemy);
            std::cout<<"here\n";
            player1.mergeEntities(enemyEntities);
            valid = true;
        }else if(type == 'S'){

        }else if(type == 'E'){

        }
    }
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
    os<< (a.getPlayer2());
    return os;
}

std::ostream& operator<<(std::ostream& os, ComputerVSComputer* a) {
    os << *a;
    return os;
}