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

int main(){

    std::vector<std::string> iFile;
    std::ifstream my_ifile("../replay.txt");
    
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

    return 0;
}
