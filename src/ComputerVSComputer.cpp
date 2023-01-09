#include "ComputerVSComputer.h"

#include <cstdlib>
#include <ctime>  //librerie per generare posizioni casuali dove piazzare le navi

ComputerVSComputer::ComputerVSComputer() { //TODO: CHECK RANDOMICITY
    srand(time(NULL));  
    bool placed;

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {

                static Battleship buffer(Position(x - 2, y), Position(x + 2, y));
                if(player1.checkUnitPlacement(&buffer)){
                    player1.addUnit(&buffer);
                    placed = true;
                }                
                
            } else {
                static Battleship buffer(Position(x, y - 2), Position(x, y + 2));
                if(player1.checkUnitPlacement(&buffer)){
                    player1.addUnit(&buffer);
                    placed = true;
                }   
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {

                static Battleship buffer(Position(x - 2, y), Position(x + 2, y));
                if(player2.checkUnitPlacement(&buffer)){
                    player2.addUnit(&buffer);
                    placed = true;
                }                
                
            } else {
                static Battleship buffer(Position(x, y - 2), Position(x, y + 2));
                if(player2.checkUnitPlacement(&buffer)){
                    player2.addUnit(&buffer);
                    placed = true;
                }   
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {
                static Support buffer(Position(x - 1, y), Position(x + 1, y));

                if(player1.checkUnitPlacement(&buffer)){
                    player1.addUnit(&buffer);
                    placed = true;
                } 

            } else {

                static Support buffer(Position(x, y - 1), Position(x, y + 1));

                if(player1.checkUnitPlacement(&buffer)){
                    player1.addUnit(&buffer);
                    placed = true;
                } 
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {

                static Support buffer(Position(x - 1, y), Position(x + 1, y));
                
               if(player2.checkUnitPlacement(&buffer)){
                    player2.addUnit(&buffer);
                    placed = true;
                } 

            } else {

                static Support buffer(Position(x, y - 1), Position(x, y + 1));
                if(player2.checkUnitPlacement(&buffer)){
                    player2.addUnit(&buffer);
                    placed = true;
                } 
            }
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sottomarini del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;

            static Submarine buffer(Position(x , y), Position(x , y));
            if(player1.checkUnitPlacement(&buffer)){
                    player1.addUnit(&buffer);
                    placed = true;
                } 
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sottomarini del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;

            // metodo per vedere se non ci sono unità che occupano la casella (x,y) da implementare in controller
            static Submarine buffer(Position(x, y), Position(x, y));
            if(player2.checkUnitPlacement(&buffer)){
                    player2.addUnit(&buffer);
                    placed = true;
                } 
        }
    }
}

Controller ComputerVSComputer::getPlayer1(){
    return player1;
}

Controller ComputerVSComputer::getPlayer2(){
    return player2;
}