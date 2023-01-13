#include "PlayerVSComputer.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>    //librerie per generare posizioni casuali dove piazzare le navi
#include <iostream>
#include <random>

/*********************************************************         
 *                    CONSTRUCTOR                        * 
**********************************************************/

PlayerVSComputer::PlayerVSComputer(){

    std::srand(std::time(nullptr));
    bool placed;
    
    // int x, y, vert;

    //Placing battleships of player1
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {

            std::shared_ptr<Battleship> buffer = inputBattleship();
            std::shared_ptr<Unit> battleShip(buffer);
            
            if(player1.checkUnitPlacement(battleShip)){
                player1.addUnit(battleShip);
                placed=true;
                
                //player1.printDefense(std::cout);
                //player1.printAttack(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }
    }
    
//Placing battleships of player2
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {

            // 1 vertical, 0 horizontal
            int vert = rand() % 2;  
            
            if (vert == 0) {
                try{
                    int x = rand() % 10 + 1;
                    int y = rand() % 12 + 1;
                    std::shared_ptr<Unit> battleShip(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    if (player2.checkUnitPlacement(battleShip)) {
                        player2.addUnit(battleShip);
                        placed = true;
                        // std::cout << Position(x, y) << ", Horiz\n";
                        //player2.printDefense(std::cout);
                        //player2.printAttack(std::cout);
                    } else {
                        // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                    }
                } catch(std::invalid_argument){
                    std::cout << "\nInvalid Pos for battleship p2" <<std::endl;
                }
                
            } else {
                try{
                    int x = rand() % 12 + 1;
                    int y = rand() % 10 + 1;
                    std::shared_ptr<Unit> battleShip(new Battleship(Position(x, y - 2), Position(x, y + 2)));
                    if (player2.checkUnitPlacement(battleShip)) {
                        player2.addUnit(battleShip);
                        placed = true;
                        // std::cout << Position(x, y) << ", Vert\n";
                        //player2.printDefense(std::cout);
                        //player2.printAttack(std::cout);
                    } else {
                        // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                    }
                } catch(std::invalid_argument){
                    std::cout << "\nInvalid Pos for battleship p2" <<std::endl;
                }
            }
        }

        std::cout << "Placed Battleship Player2!\n";
    }



    //Placing supports of player1
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {
        
            std::shared_ptr<Support> buffer =inputSupport();
            std::shared_ptr<Unit> support(buffer);

            if (player1.checkUnitPlacement(support)){
                player1.addUnit(support);
                placed=true;
                
                //player1.printDefense(std::cout);
                //player1.printAttack(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }   
    }
    
    //Placing supports of player2
    for (int i = 0; i < 3; i++) { 
        placed = false;
        while (!placed) {

            // 1 vertical, 0 horizontal
            int vert = rand() % 2;  

            if (vert == 0) {
                try{
                    int x = rand() % 11 + 1;
                    int y = rand() % 12 + 1;
                    std::shared_ptr<Unit> support(new Support(Position(x - 1, y), Position(x + 1, y)));
                    if (player2.checkUnitPlacement(support)) {
                        player2.addUnit(support);
                        placed = true;
                        // std::cout << Position(x, y) << ", Horiz\n";
                        //player2.printDefense(std::cout);
                        //player2.printAttack(std::cout);
                    } else {
                        // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                    }
                } catch(std::invalid_argument){
                    std::cout << "\nInvalid Pos for support p2" <<std::endl;
                } 

            } else {

                try{
                    int x = rand() % 12 + 1;
                    int y = rand() % 11 + 1;
                    std::shared_ptr<Unit> support(new Support(Position(x, y - 1), Position(x, y + 1)));
                    if (player2.checkUnitPlacement(support)) {
                        player2.addUnit(support);
                        placed = true;
                        // std::cout << Position(x, y) << ", Vert\n";
                        //player2.printDefense(std::cout);
                        //player2.printAttack(std::cout);
                    } else {
                        // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                    }

                } catch(std::invalid_argument){
                    std::cout << "\nInvalid Pos for support p2" <<std::endl;
                } 
                
            }
        }

        std::cout << "Placed supports Player2!\n";
    }

    //Placing submarines of player1
    for (int i = 0; i < 2; i++) {  
        placed = false;
        while (!placed) {
            
            std::shared_ptr<Submarine> buffer = inputSubmarine();
            std::shared_ptr<Unit> submarine(buffer);
            if(player1.checkUnitPlacement(submarine)){
                player1.addUnit(submarine);
                placed=true;
                
                //player1.printDefense(std::cout);
                //player1.printAttack(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }
    }

    //Placing submarines of player2
    for (int i = 0; i < 2; i++) {  
        placed = false;
        while (!placed) {
            try{
                int x = rand() % 12 + 1;
                int y = rand() % 12 + 1;
                std::shared_ptr<Unit> submarine(new Submarine(Position(x, y), Position(x, y)));
                if (!player2.isUnit(Position(x, y))) {
                    player2.addUnit(submarine);
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    //player2.printDefense(std::cout);
                    //player2.printAttack(std::cout);
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            } catch(std::invalid_argument){
                std::cout << "\nInvalid Pos for submarine p2" <<std::endl;
            } 
            
        }

        std::cout << "Placed submarine Player2!\n";
    }
}

/*********************************************************         
 *                  GETTER FUNCTIONS                     * 
**********************************************************/

Controller *PlayerVSComputer::getPlayer1() {
    return &player1;
}

Controller *PlayerVSComputer::getPlayer2() {
    return &player2;
}

/*********************************************************         
 *                  HELPER FUNCTIONS                     * 
**********************************************************/

std::ostream& operator<<(std::ostream& os, PlayerVSComputer& a) {
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream& operator<<(std::ostream& os, PlayerVSComputer* a) {
    os << *a;
    return os;
}

int stringTointeger(std::string str){
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

std::vector<Position> inputManipolation(){

    std::string in{};
    std::getline(std::cin, in, '\n');
    //std::cout << in;

    std::string XY1 = in.substr(0, in.find(" "));
    std::string XY2 = in.substr(in.find(" ")+1, in.npos);

    std::cout << "\n";
    std::cout << XY1 << "\n";
    std::cout << XY2 << "\n";

    char y1 = XY1[0];
    std::string strx1 = XY1.substr(1, XY1.length()-1); // estrazione dei caratteri dall'inizio all'ultimo-1
    int x1 = stringTointeger(strx1);
     // estrazione dell'ultimo carattere

    //std::cout << "X: " << x1 << std::endl;
    //std::cout << "Y: " << y1 << std::endl;

    
    char y2=XY2[0];
    std::string stry2 = XY2.substr(1, XY2.length()-1); // estrazione dei caratteri dall'inizio all'ultimo-1
    char x2 = stringTointeger(stry2);                  // estrazione dell'ultimo carattere

    //std::cout << "X: " << x2 << std::endl;
    //std::cout << "Y: " << y2 << std::endl;

    //TODO: eccezioni position costruttori
    Position bow(x1,y1);
    Position stern(x2,y2);
    return std::vector<Position> {bow,stern}; 
}


std::shared_ptr<Battleship> inputBattleship(){
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave corazzata \n";
        try {
            
            std::vector<Position> iPositions {inputManipolation()}; 
            
            //Battleship* iBattleship = new Battleship(iPositions.at(0), iPositions.at(1));
            
            std::shared_ptr<Battleship> iBattleship(new Battleship(iPositions.at(0), iPositions.at(1)));
            
            std::cout<<iBattleship<<"\n";
            return iBattleship;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Battlehip\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}

std::shared_ptr<Support> inputSupport(){
     bool done = false;
     while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave supporto \n";
        try {
            std::vector<Position> iPositions {inputManipolation()}; 
            std::shared_ptr<Support> iSupport(new Support(iPositions.at(0), iPositions.at(1)));

            //Support* iSupport= new Support(iPositions.at(0), iPositions.at(1));
            return iSupport;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Support\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}

std::shared_ptr<Submarine> inputSubmarine(){
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave sottomarino \n";
        try {
            std::vector<Position> iPositions {inputManipolation()}; 
            std::shared_ptr<Submarine> iSubmarine(new Submarine(iPositions.at(0), iPositions.at(1)));

            //Submarine* iSubmarine= new Submarine(iPositions.at(0), iPositions.at(1));
            return iSubmarine;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Submarine\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}