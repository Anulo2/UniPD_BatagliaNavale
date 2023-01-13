#include "inputHelper.h"
#include <ctime>    //librerie per generare posizioni casuali dove piazzare le navi


int stringTointeger(std::string str){
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
}



std::shared_ptr<Unit> randomBattleship(){
    
    //1 vertical, 0 horizontal
    int vert = rand() % 2;  
    if (vert == 0) {

          
        int x = rand() % 8 + 3;
        int y = rand() % 12 + 1;
        std::shared_ptr<Unit> battleShip(new Battleship(Position(x - 2, y), Position(x + 2, y)));
        return battleShip;
        
    } 
    else {
            
        int x = rand() % 12 + 1;
        int y = rand() % 8 + 3;
        std::shared_ptr<Unit> buffer(new Battleship(Position(x, y - 2), Position(x, y + 2)));
        return buffer;
        
    }    
    
}

std::shared_ptr<Unit> randomSupport(){
    //1 vertical, 0 horizontal
    
    int vert = rand() % 2;  
    if (vert == 0) {
            
        int x = rand()%10+2;
        int y = rand()%12+1;
        std::shared_ptr<Unit> buffer(new Support(Position(x - 1, y), Position(x + 1, y)));
        return buffer;
        
    } 
    else {
            
        int x = rand()%10+2;
        int y = rand()%12+1;
        std::shared_ptr<Unit> buffer(new Support(Position(x, y - 1), Position(x, y + 1)));
        return buffer;
    }    
      
}

std::shared_ptr<Unit> randomSubmarine(){
    
    int x = rand() % 12 + 1;
    int y = rand() % 12 + 1;
    std::shared_ptr<Unit> buffer(new Submarine(Position(x, y), Position(x, y)));
    return buffer;
}