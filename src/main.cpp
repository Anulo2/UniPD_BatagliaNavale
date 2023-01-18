
// Eris Sanson

#include <string.h>

#include <fstream>
#include <iostream>
#include <random>

#include "ComputerVSComputer.h"
#include "PlayerVSComputer.h"

static const int MAX_TURNS = 5000;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "\n!!Invalid arguments!!\nYou can use parameter: pc or cc\n\n";
        return 0;
    }
    if (strcmp(argv[1], "pc") == 0) {  // partita player vs computer

        std::cout << "######################################\n";
        std::cout << "########   PLAYER VS COMPUTER   ######\n";
        std::cout << "######################################\n";

        std::cout << "\n\nTo place the ships type bow and stern coords!\n";
        std::cout << "\nExample: A5 B10\n";

        PlayerVSComputer playerVsComputer;

        std::cout << playerVsComputer.getPlayer1();

        std::ofstream my_oFileB("./logs/mainLogPLVSPC.txt");

        bool win = false;

        for (int i = 0; i < MAX_TURNS && !win; i++) {
            std::cout << "\n\n";

            if (!win && ((i + playerVsComputer.getStartingPlayer()) % 2 == 0)) {
                playerVsComputer.addStringToLog(Helper::handlePlayerAction(playerVsComputer.getPlayer1(), playerVsComputer.getPlayer2(), ""));
                win = playerVsComputer.getPlayer2()->isDead();
            }
            std::cout << "\n\n";

            if (!win && ((i + playerVsComputer.getStartingPlayer()) % 2 == 1)) {
                playerVsComputer.addStringToLog(Helper::randomAction(playerVsComputer.getPlayer2(), playerVsComputer.getPlayer1()));
                win = playerVsComputer.getPlayer1()->isDead();
            }

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
            my_oFileB << Helper::logToString(playerVsComputer.getLog());
            my_oFileB.flush();
        }
        if (!playerVsComputer.getPlayer1()->isDead() && !playerVsComputer.getPlayer2()->isDead()) {
            std::cout << "######################################\n";
            std::cout << "########           DRAW         ######\n";
            std::cout << "######################################\n";
        }

        std::cout << "\n You can find the log of the game in mainLogPLVSPC.txt !\n";
        my_oFileB.close();

    } else if (strcmp(argv[1], "cc") == 0) {  // partita computer vs computer
        std::cout.setstate(std::ios_base::failbit);
        std::cout << "######################################\n";
        std::cout << "########  COMPUTER VS COMPUTER  ######\n";
        std::cout << "######################################\n";

        ComputerVSComputer computerVsComputer;

        std::cout << computerVsComputer;
        std::ofstream my_oFileA("./logs/mainLogPCVSPC.txt");

        bool win = false;
        for (int i = 0; i < MAX_TURNS && !win; i++) {
            if (!win && ((i + computerVsComputer.getStartingPlayer()) % 2 == 0)) {
                std::cout << "\t     COMPUTER 1 ACTION \t\t\n\n";
                computerVsComputer.addStringToLog(Helper::randomAction(computerVsComputer.getPlayer1(), computerVsComputer.getPlayer2()));
                std::cout << computerVsComputer.getPlayer1();

                win = computerVsComputer.getPlayer2()->isDead();
            }
            if (!win && ((i + computerVsComputer.getStartingPlayer()) % 2 == 1)) {
                std::cout << "\t     COMPUTER 2 ACTION \t\t\n\n";
                computerVsComputer.addStringToLog(Helper::randomAction(computerVsComputer.getPlayer2(), computerVsComputer.getPlayer1()));
                std::cout << computerVsComputer.getPlayer2();
                win = computerVsComputer.getPlayer1()->isDead();
            }

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
            my_oFileA << Helper::logToString(computerVsComputer.getLog());
            my_oFileA.flush();
        }
        if (!computerVsComputer.getPlayer1()->isDead() && !computerVsComputer.getPlayer2()->isDead()) {
            std::cout << "######################################\n";
            std::cout << "########          DRAW          ######\n";
            std::cout << "######################################\n";
        }

        std::cout << computerVsComputer;
        std::cout.clear();
        std::cout << "\n You can find the log of the game in mainLogPCVSPC.txt !\n";
        my_oFileA.close();

    } else {
        std::cout << "\n!!Invalid arguments!!\nYou can use parameter: pc or cc\n\n";
    }

    return 0;
}