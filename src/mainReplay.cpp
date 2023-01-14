#include <fstream>
#include <iostream>

#include "Controller.h"
#include "Entity.h"
#include "Battleship.h"
#include "Support.h"
#include "Submarine.h"
#include "Unit.h"
#include "Position.h"

#include "Replay.h"

int main(int argc, char** argv){

    std::cout<<"####################################\n";
    std::cout<<"###          REPLAY              ###\n";
    std::cout<<"####################################\n";

    std::vector<std::string> iFile;
    std::ifstream my_ifile(argv[1]);
    
    if (my_ifile.is_open()) {
        std::string line;
        while (getline(my_ifile, line)) {
            iFile.push_back(line);
        }
        my_ifile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    Replay a(iFile);
    std::cout << a.getPlayer1() << std::endl;
    std::cout << a.getPlayer2() << std::endl;
    return 0;
}
