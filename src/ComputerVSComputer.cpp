#include "ComputerVSComputer.h"

ComputerVSComputer::ComputerVSComputer() {
    std::random_device rand;
    std::uniform_int_distribution<int> ranomPlayer(0, 1);
    // true  = player 1
    selectPlayer = ranomPlayer(rand);
    int placing = 0;
    bool placed;
    bool placedUnitP1 = false;
    bool placedUnitP2 = false;

    while (!placed) {
        if (selectPlayer == 0) {
            // Placing battleships of player1
            Game::placeUnits(player1, Helper::unitType::random_battleship, 3);

            // Placing support of player1
            Game::placeUnits(player1, Helper::unitType::random_support, 3);

            // Placing submarines of player1
            Game::placeUnits(player1, Helper::unitType::random_submarine, 2);
            placedUnitP1 = true;
        }
        if (selectPlayer == 1) {
            // Placing battleships of player2
            Game::placeUnits(player2, Helper::unitType::random_battleship, 3);

            // Placing support of player2
            Game::placeUnits(player2, Helper::unitType::random_support, 3);
            // Placing submarines of player2
            Game::placeUnits(player2, Helper::unitType::random_submarine, 2);
            placedUnitP2 = true;
        }

        if (selectPlayer == 0) {
            selectPlayer++;
        } else {
            selectPlayer--;
        }
        if (placedUnitP1 && placedUnitP2) placed = true;
    }
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a) {
    // inputHelper::writeLog(os, a.getLog());
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a) {
    os << *a;
    return os;
}