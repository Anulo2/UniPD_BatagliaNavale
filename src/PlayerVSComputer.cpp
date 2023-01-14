#include "PlayerVSComputer.h"

/*********************************************************         
 *                    CONSTRUCTOR                        * 
**********************************************************/

PlayerVSComputer::PlayerVSComputer(){

    bool placed;
    
    // int x, y, vert;

    //Placing battleships of player1
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {

            std::shared_ptr<Battleship> buffer = inputHelper::inputBattleship(inputHelper::getPlayerInput(std::cin));
            std::shared_ptr<Unit> battleShip(buffer);
            
            if(player1.checkUnitPlacement(battleShip)){
                player1.addUnit(battleShip);
                placed=true;
                
                // player1.printDefense(std::cout);
                // player1.printAttack(std::cout);
            }
            else{
                std::cout<<"input non valido, c'è gia una nave\n";
            }
        }
        std::cout<<"Battleship player1 n."<<i+1<<" placed!\n";
        player1.printDefense(std::cout);
    }
    
//Placing battleships of player2
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {            
            
            try{
                
                std::shared_ptr<Unit> buffer(inputHelper::randomBattleship());
                if (player2.checkUnitPlacement(buffer)) {
                    player2.addUnit(buffer);
                    placed = true;
                    
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch(std::invalid_argument e){
                std::cout << "\nInvalid Pos for battleship p2 \n" <<std::endl;
                std::cout << e.what()<<"\n";
            }
            
        }

        std::cout<<"Battleship player2 n."<<i+1<<" placed!\n";
        player2.printDefense(std::cout);
    }



    //Placing supports of player1
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {
        
            std::shared_ptr<Support> buffer = inputHelper::inputSupport(inputHelper::getPlayerInput(std::cin));
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
        std::cout<<"Support player1 n."<<i+1<<" placed!\n";
        player1.printDefense(std::cout); 
    }
    
    //Placing supports of player2
    for (int i = 0; i < 3; i++) {  
        placed = false;
        while (!placed) {            
            
            try{
                
                std::shared_ptr<Unit> buffer(inputHelper::randomSupport());
                if (player2.checkUnitPlacement(buffer)) {
                    player2.addUnit(buffer);
                    placed = true;
                } else {
                    // std::cout << "Failed to place vertical support of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch(std::invalid_argument e){
                std::cout << "\n"<<e.what() <<std::endl;
            }
            
        }

        std::cout<<"Support player2 n."<<i+1<<" placed!\n";
        player2.printDefense(std::cout);
    }

    //Placing submarines of player1
    for (int i = 0; i < 2; i++) {  
        placed = false;
        while (!placed) {
            
            std::shared_ptr<Submarine> buffer = inputHelper::inputSubmarine(inputHelper::getPlayerInput(std::cin));
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
        std::cout<<"Submarine player1 n."<<i+1<<" placed!\n";
        player1.printDefense(std::cout);
    }

    //Placing submarines of player2
    for (int i = 0; i < 2; i++) {  
        placed = false;
        while (!placed) {            
            
            try{
                
                std::shared_ptr<Unit> buffer(inputHelper::randomSubmarine());
                if (player2.checkUnitPlacement(buffer)) {
                    player2.addUnit(buffer);
                    placed = true;
                } else {
                    // std::cout << "Failed to place vertical submarine of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch(std::invalid_argument e){
                std::cout << "\nInvalid Pos for submarine p2 \n" <<std::endl;
                std::cout << e.what()<<"\n";
            }
            
        }

        std::cout<<"Submarine player2 n."<<i+1<<" placed!\n";
        player2.printDefense(std::cout);
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

/*int stringTointeger(std::string str){
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

std::vector<Position> inputManipolation(std::istream& is){

    std::string in{};
    std::getline(is, in, '\n');
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


std::shared_ptr<Battleship> inputBattleship(std::istream& is){
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave corazzata \n";
        try {
            
            std::vector<Position> iPositions {inputManipolation(is)}; 
            
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

std::shared_ptr<Support> inputSupport(std::istream& is){
     bool done = false;
     while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave supporto \n";
        try {
            std::vector<Position> iPositions {inputManipolation(is)}; 
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

std::shared_ptr<Submarine> inputSubmarine(std::istream& is){
    bool done = false;
    while (!done) {
        std::cout<<"inserire posizioni poppa e prua nave sottomarino \n";
        try {
            std::vector<Position> iPositions {inputManipolation(is)}; 
            std::shared_ptr<Submarine> iSubmarine(new Submarine(iPositions.at(0), iPositions.at(1)));

            //Submarine* iSubmarine= new Submarine(iPositions.at(0), iPositions.at(1));
            return iSubmarine;
        } catch (std::invalid_argument e) {
            std::cout<<"eccezione input Submarine\n";
            std::cout<<e.what();
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
    return nullptr;
}*/