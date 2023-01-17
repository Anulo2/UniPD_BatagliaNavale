#include <fstream>
#include <iostream>
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

static const int MAX_TURNS = 5000;

int main(int argc, char *argv[]) {

    // TODO: CONTROLLO CHE VENGA PASSATO UN ARGOMENTO

    if (strcmp(argv[1], "pc") == 0) { // partita player vs computer

        std::cout << "######################################\n";
        std::cout << "########   PLAYER VS COMPUTER   ######\n";
        std::cout << "######################################\n";

        std::cout << "\n\nPer posizionare le navi inserisci le coordinate di poppa e prua!\n";
        std::cout << "\nCoordinate esempio: A5 B10\n";

        PlayerVSComputer playerVsComputer;

        std::cout << playerVsComputer.getPlayer1();

        // TODO TESTARE INPUT
        for (int i = 0; i < MAX_TURNS && (!playerVsComputer.getPlayer1()->isDead() && !playerVsComputer.getPlayer2()->isDead()); i++) {

            playerVsComputer.addStringToLog(inputHelper::handlePlayerAction(playerVsComputer.getPlayer1(), playerVsComputer.getPlayer2(), ""));

            playerVsComputer.addStringToLog(inputHelper::randomAction(playerVsComputer.getPlayer2(), playerVsComputer.getPlayer1()));
            
            std::cout<<"\n\n";

            if (playerVsComputer.getPlayer1()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        HAI PERSO       ######\n";
                std::cout << "######################################\n";
            }
            if (playerVsComputer.getPlayer2()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        HAI VINTO       ######\n";
                std::cout << "######################################\n";
            }
        }
        if ((!playerVsComputer.getPlayer1()->isDead() && !playerVsComputer.getPlayer2()->isDead())) {
            std::cout << "######################################\n";
            std::cout << "########          PATTA         ######\n";
            std::cout << "######################################\n";
        }

        std::ofstream my_oFileB("../mainLogPLVSPC.txt");
        my_oFileB << inputHelper::logToString(playerVsComputer.getLog());
        std::cout<<"\n You can find the log of the game in mainLogPLVSPC.txt !\n";
        my_oFileB.close();

    } else if (strcmp(argv[1], "cc") == 0) { // partita computer vs computer

        std::cout << "######################################\n";
        std::cout << "########  COMPUTER VS COMPUTER  ######\n";
        std::cout << "######################################\n";

        ComputerVSComputer computerVsComputer;

        std::cout << computerVsComputer;

        for (int i = 0; i < MAX_TURNS && (!computerVsComputer.getPlayer1()->isDead() && !computerVsComputer.getPlayer2()->isDead()); i++) {

            computerVsComputer.addStringToLog(inputHelper::randomAction(computerVsComputer.getPlayer1(), computerVsComputer.getPlayer2()));
            
            std::cout << "    COMPUTER 1 ACTION   \n";
            std::cout<<computerVsComputer.getPlayer1();
            
            computerVsComputer.addStringToLog(inputHelper::randomAction(computerVsComputer.getPlayer2(), computerVsComputer.getPlayer1()));
            std::cout << "    COMPUTER 2 ACTION   \n";
            std::cout<<computerVsComputer.getPlayer2();

            if (computerVsComputer.getPlayer2()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        VINCE PC1       ######\n";
                std::cout << "######################################\n";
            }
            if (computerVsComputer.getPlayer1()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        VINCE PC2       ######\n";
                std::cout << "######################################\n";
            }
        }
        if ((!computerVsComputer.getPlayer1()->isDead() && !computerVsComputer.getPlayer2()->isDead())) {
            std::cout << "######################################\n";
            std::cout << "########          PATTA         ######\n";
            std::cout << "######################################\n";
        }

        std::cout << computerVsComputer;

        std::ofstream my_oFileA("../mainLogPCVSPC.txt");
        my_oFileA << inputHelper::logToString(computerVsComputer.getLog());
        std::cout<<"\n You can find the log of the game in mainLogPCVSPC.txt !\n";
        my_oFileA.close();

    } else {
        std::cerr << "\n!!Invalid arguments!!\nYou can use parameter: pc or cc\n\n";
    }

    return 0;
}