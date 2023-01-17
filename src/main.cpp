#include <string.h>

#include <fstream>
#include <iostream>

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
    if (strcmp(argv[1], "pc") == 0) {  // partita player vs computer

        std::cout << "######################################\n";
        std::cout << "########   PLAYER VS COMPUTER   ######\n";
        std::cout << "######################################\n";

        std::cout << "\n\nTo place the ships type bow and stern coords!\n";
        std::cout << "\nExample: A5 B10\n";

        PlayerVSComputer playerVsComputer;

        std::cout << playerVsComputer.getPlayer1();

        std::ofstream my_oFileB("./logs/mainLogPLVSPC.txt");

        for (int i = 0; i < MAX_TURNS && (!playerVsComputer.getPlayer1()->isDead() && !playerVsComputer.getPlayer2()->isDead()); i++) {
            std::cout << "\n\n";

            playerVsComputer.addStringToLog(inputHelper::handlePlayerAction(playerVsComputer.getPlayer1(), playerVsComputer.getPlayer2(), ""));
            std::cout << "\n\n";

            playerVsComputer.addStringToLog(inputHelper::randomAction(playerVsComputer.getPlayer2(), playerVsComputer.getPlayer1()));
            std::cout << playerVsComputer;  // TODO: RIMUOVERE

            std::cout << "\n\n";

            if (playerVsComputer.getPlayer1()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        YOU LOSE        ######\n";
                std::cout << "######################################\n";
            }
            if (playerVsComputer.getPlayer2()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        YOU WIN        ######\n";
                std::cout << "######################################\n";
            }
            my_oFileB << inputHelper::logToString(playerVsComputer.getLog());
            my_oFileB.flush();
        }
        if ((!playerVsComputer.getPlayer1()->isDead() && !playerVsComputer.getPlayer2()->isDead())) {
            std::cout << "######################################\n";
            std::cout << "########           DRAW         ######\n";
            std::cout << "######################################\n";
        }

        std::cout << "\n You can find the log of the game in mainLogPLVSPC.txt !\n";
        my_oFileB.close();

    } else if (strcmp(argv[1], "cc") == 0) {  // partita computer vs computer

        std::cout << "######################################\n";
        std::cout << "########  COMPUTER VS COMPUTER  ######\n";
        std::cout << "######################################\n";

        ComputerVSComputer computerVsComputer;

        std::cout << computerVsComputer;
        std::ofstream my_oFileA("./logs/mainLogPCVSPC.txt");

        for (int i = 0; i < MAX_TURNS && (!computerVsComputer.getPlayer1()->isDead() && !computerVsComputer.getPlayer2()->isDead()); i++) {
            computerVsComputer.addStringToLog(inputHelper::randomAction(computerVsComputer.getPlayer1(), computerVsComputer.getPlayer2()));

            std::cout << "    COMPUTER 1 ACTION   \n";
            std::cout << computerVsComputer.getPlayer1();

            computerVsComputer.addStringToLog(inputHelper::randomAction(computerVsComputer.getPlayer2(), computerVsComputer.getPlayer1()));
            std::cout << "    COMPUTER 2 ACTION   \n";
            std::cout << computerVsComputer.getPlayer2();

            if (computerVsComputer.getPlayer2()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        PC1 WIN         ######\n";
                std::cout << "######################################\n";
            }
            if (computerVsComputer.getPlayer1()->isDead()) {
                std::cout << "######################################\n";
                std::cout << "########        PC2 WIN         ######\n";
                std::cout << "######################################\n";
            }
            my_oFileA << inputHelper::logToString(computerVsComputer.getLog());
            my_oFileA.flush();
        }
        if ((!computerVsComputer.getPlayer1()->isDead() && !computerVsComputer.getPlayer2()->isDead())) {
            std::cout << "######################################\n";
            std::cout << "########          DRAW          ######\n";
            std::cout << "######################################\n";
        }

        std::cout << computerVsComputer;

        std::cout << "\n You can find the log of the game in mainLogPCVSPC.txt !\n";
        my_oFileA.close();

    } else {
        std::cout << "\n!!Invalid arguments!!\nYou can use parameter: pc or cc\n\n";
    }

    return 0;
}