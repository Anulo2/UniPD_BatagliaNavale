#include <iostream>
#include <fstream>
#include <string.h>

#include "Battleship.h"
#include "ComputerVSComputer.h"
#include "Controller.h"
#include "Entity.h"
#include "PlayerVSComputer.h"
#include "Position.h"
#include "Submarine.h"
#include "Support.h"
#include "Unit.h"


using namespace std;

int main(int argc, char* argv[]){

    bool invalid = false;

    if(strcmp(argv[1],"pc")==0){

        std::cout<<"######################################\n";
        std::cout<<"########   PLAYER VS COMPUTER   ######\n";
        std::cout<<"######################################\n";

        std::cout<<"\n\nPer posizionare le navi inserisci le coordinate di poppa e prua!\n";
        std::cout<<"\n\nCoordinate esempio: A5 B10\n";

        PlayerVSComputer playerVsComputer;
        
        std::cout<<playerVsComputer;

        //TODO TESTARE INPUT
        while(!invalid){
            
            playerVsComputer.addStringToLog(inputHelper::handlePlayerAction(playerVsComputer.getPlayer1(), playerVsComputer.getPlayer2(),""));

            playerVsComputer.addStringToLog(inputHelper::randomAction(playerVsComputer.getPlayer2(), playerVsComputer.getPlayer1()));

            if (playerVsComputer.getPlayer1()->isDead()){
                std::cout << "Hai Perso!"<<std::endl;
                invalid = true;
            }
            if (playerVsComputer.getPlayer2()->isDead()){
                std::cout << "Hai vinto!" <<std::endl;
                invalid = true;
            }
        }
        
        std::cout<<playerVsComputer;

        std::ofstream my_oFileB("../mainLogPLVSPC.txt");
        my_oFileB <<inputHelper::logToString(playerVsComputer.getLog());
        my_oFileB.close();

    }else if(strcmp(argv[1],"cc")==0){

        std::cout<<"######################################\n";
        std::cout<<"########  COMPUTER VS COMPUTER  ######\n";
        std::cout<<"######################################\n";

        ComputerVSComputer computerVsComputer;
       
        std::cout<<computerVsComputer;
    
        
        while(!invalid){

            computerVsComputer.addStringToLog(inputHelper::randomAction(computerVsComputer.getPlayer1(), computerVsComputer.getPlayer2()));

            computerVsComputer.addStringToLog(inputHelper::randomAction(computerVsComputer.getPlayer2(), computerVsComputer.getPlayer1()));
        
            if (computerVsComputer.getPlayer1()->isDead()){
                std::cout << "Hai Perso!"<<std::endl;
                invalid = true;
            }
            if (computerVsComputer.getPlayer2()->isDead()){
                std::cout << "Hai vinto!" <<std::endl;
                invalid = true;
            }
        }
        
        std::cout<<computerVsComputer;
    
        std::ofstream my_oFileA("../mainLogPCVSPC.txt");
        my_oFileA <<inputHelper::logToString(computerVsComputer.getLog());
        my_oFileA.close();

    } else {
        std::cerr << "\n!!Invalid arguments!!\nYou can use parameter: pc or cc\n\n";
    }
        
    return  0;
}