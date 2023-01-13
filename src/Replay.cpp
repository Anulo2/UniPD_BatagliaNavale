#include "Replay.h"
#include <iostream>
/*********************************************************         
 *                    CONSTRUCTOR                        * 
**********************************************************/

Replay::Replay(std::vector<std::string> in){
    bool placed;
    int iterator = 0;
    static const int nTotalUnitsInGame = 16;

    while(iterator <= nTotalUnitsInGame){

        //Placing battleships of player1
        for (int i = 0; i < 3; i++) {
            std::cout <<"Input String: \n" << in[iterator] <<std::endl;
            placed = false;
            while (!placed) {

                std::shared_ptr<Battleship> buffer = inputBattleship(in[iterator]);
                std::shared_ptr<Unit> battleShip(buffer);

                if(player1.checkUnitPlacement(battleShip)){
                    player1.addUnit(battleShip);
                    placed=true;
                    player1.printDefense(std::cout);
                }
                else{
                    std::cout<<"input non valido, c'è gia una nave\n";
                }
            }
            iterator++;
        }

        //Placing battleships of player2
        for (int i = 0; i < 3; i++) {  
            placed = false;
            while (!placed) {

                std::shared_ptr<Battleship> buffer = inputBattleship(in[iterator]);
                std::shared_ptr<Unit> battleShip(buffer);
                
                if(player2.checkUnitPlacement(battleShip)){
                    player2.addUnit(battleShip);
                    placed=true;
                    player2.printDefense(std::cout);
                }
                else{
                    std::cout<<"input non valido, c'è gia una nave\n";
                }
            }
            iterator++;
        }

        //Placing supports of player1
        for (int i = 0; i < 3; i++) {
            placed = false;
            while (!placed) {

                std::shared_ptr<Support> buffer = inputSupport(in[iterator]);
                std::shared_ptr<Unit> support(buffer);

                if(player1.checkUnitPlacement(support)){
                    player1.addUnit(support);
                    placed=true;
                    player1.printDefense(std::cout);
                }
                else{
                    std::cout<<"input non valido, c'è gia una nave\n";
                }
            }
            iterator++;
        }

        //Placing supports of player2
        for (int i = 0; i < 3; i++) {
            placed = false;
            while (!placed) {

                std::shared_ptr<Support> buffer = inputSupport(in[iterator]);
                std::shared_ptr<Unit> support(buffer);

                if(player2.checkUnitPlacement(support)){
                    player2.addUnit(support);
                    placed=true;
                    player2.printDefense(std::cout);
                }
                else{
                    std::cout<<"input non valido, c'è gia una nave\n";
                }
            }
            iterator++;
        }

        //Placing submarines of player1
        for (int i = 0; i < 2; i++) {  
            placed = false;
            while (!placed) {
                
                std::shared_ptr<Submarine> buffer = inputSubmarine(in[iterator]);
                std::shared_ptr<Unit> submarine(buffer);

                if(player1.checkUnitPlacement(submarine)){
                    player1.addUnit(submarine);
                    placed=true;
                    player1.printDefense(std::cout);
                }
                else{
                    std::cout<<"input non valido, c'è gia una nave\n";
                }
            }
            iterator++;
        }

        //Placing submarines of player1
        for (int i = 0; i < 2; i++) {  
            placed = false;
            while (!placed) {
                
                std::shared_ptr<Submarine> buffer = inputSubmarine(in[iterator]);
                std::shared_ptr<Unit> submarine(buffer);

                if(player2.checkUnitPlacement(submarine)){
                    player2.addUnit(submarine);
                    placed=true;
                    player2.printDefense(std::cout);
                }
                else{
                    std::cout<<"input non valido, c'è gia una nave\n";
                }
            }
            iterator++;
        }

        std::cout << "iterator: " << iterator <<std::endl;
        // end placing unit
    }//end of while
}


Controller *Replay::getPlayer1() {
    return &player1;
}

Controller *Replay::getPlayer2() {
    return &player2;
}


/*********************************************************         
 *                  HELPER FUNCTIONS                     * 
**********************************************************/

int stringTointeger(std::string str){
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

std::vector<Position> inputString(std::string in){

    std::string XY1 = in.substr(0, in.find(" "));
    std::string XY2 = in.substr(in.find(" ")+1, in.npos);

    if(XY2.length() > 2)
        XY2 = XY2.substr(0, XY2.find(" "));

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

std::shared_ptr<Battleship> inputBattleship(const std::string in){
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave corazzata \n";
        try {
            
            std::vector<Position> iPositions {inputString(in)};
            
            std::shared_ptr<Battleship> iBattleship(new Battleship(iPositions.at(0), iPositions.at(1)));
            
            //Battleship *iBattleship = new Battleship(iPositions.at(0), iPositions.at(1));
            std::cout<<iBattleship<<"\n";
            return iBattleship;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Battlehip\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}

std::shared_ptr<Support> inputSupport(const std::string in) {
     bool done = false;
     while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave supporto \n";
        try {
            std::vector<Position> iPositions {inputString(in)}; 
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

std::shared_ptr<Submarine> inputSubmarine(const std::string in) {
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave sottomarino \n";
        try {
            std::vector<Position> iPositions{inputString(in)};
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