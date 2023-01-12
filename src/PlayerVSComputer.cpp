#include "PlayerVSComputer.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>  //librerie per generare posizioni casuali dove piazzare le navi
#include <iostream>
#include <random>

PlayerVSComputer::PlayerVSComputer()
{
    std::srand(std::time(nullptr));
    bool placed;
    // int x, y, vert;
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            
            Battleship* buffer =inputBattleship();
            if(player1.checkUnitPlacement(buffer)){
                player1.addUnit(buffer);
                placed=true;
                player1.printDefense(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player2 ranodm
        placed = false;
        while (!placed) {
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 10 + 1;
                int y = rand() % 12 + 1;
                if (player2.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))) {
                    player2.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                    player2.printDefense(std::cout);
                    }

            } else {
                int x = rand() % 12 + 1;
                int y = rand() % 10 + 1;
                if (player2.checkUnitPlacement(new Battleship(Position(x, y - 2), Position(x, y + 2)))) {
                    player2.addUnit(new Battleship(Position(x, y - 2), Position(x, y + 2)));
                    placed = true;
                    player2.printDefense(std::cout);
                    }
            }
        }
    }



      // piazzo i supporti del player1
    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player1
        placed = false;
        while (!placed) {
        
            Support* buffer =inputSupport();
            if(player1.checkUnitPlacement(buffer)){
                player1.addUnit(buffer);
                placed=true;
                player1.printDefense(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }   
    }
    
    
    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player2
        placed = false;
        while (!placed) {
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 11 + 1;
                int y = rand() % 12 + 1;
                if (player2.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                    player2.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                    player2.printDefense(std::cout);
                    }

            } else {
                int x = rand() % 12 + 1;
                int y = rand() % 11 + 1;
                if (player2.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                    player2.addUnit(new Support(Position(x, y - 1), Position(x, y + 1)));
                    placed = true;
                    player2.printDefense(std::cout);
                }
            }
        }

        // std::cout << "Placed Battleship Player1!\n";
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sttomarini del player1
        placed = false;
        while (!placed) {
            
            Submarine* buffer =inputSubmarine();
            if(player1.checkUnitPlacement(buffer)){
                player1.addUnit(buffer);
                placed=true;
                player1.printDefense(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sottomarini del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            if (!player2.isUnit(Position(x, y))) {
                player2.addUnit(new Submarine(Position(x, y), Position(x, y)));
                placed = true;
                player2.printDefense(std::cout);
                }
        }
    }
}

Controller *PlayerVSComputer::getPlayer1() {
    return &player1;
}

Controller *PlayerVSComputer::getPlayer2() {
    return &player2;
}

std::vector<Position> inputManipolation()
{
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


int stringTointeger(std::string str){
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
 
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get
        // the integer value of the digit.
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

Battleship *inputBattleship(void)
{
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave corazzata \n";
        try {
            
            std::vector<Position> iPositions {inputManipolation()}; 
            Battleship* iBattleship = new Battleship(iPositions.at(0), iPositions.at(1));
            std::cout<<iBattleship<<"\n";
            return iBattleship;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Battlehip\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}

Support *inputSupport() {
     bool done = false;
     while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave supporto \n";
        try {
            std::vector<Position> iPositions {inputManipolation()}; 
            Support* iSupport= new Support(iPositions.at(0), iPositions.at(1));
            return iSupport;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Support\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}

Submarine *inputSubmarine() {
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave sottomarino \n";
        try {
            std::vector<Position> iPositions {inputManipolation()}; 
            Submarine* iSubmarine= new Submarine(iPositions.at(0), iPositions.at(1));
            return iSubmarine;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Submarine\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}