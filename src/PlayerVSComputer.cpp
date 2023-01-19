// Leonardo Canello

#include "PlayerVSComputer.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/

PlayerVSComputer::PlayerVSComputer() {
}

void PlayerVSComputer::startGame() {
    Game::startGame();

    if (selectPlayer == 0) {
        placePlayerUnits(player1);
        placeComputerUnits(player2);

    } else {
        placeComputerUnits(player2);
        placePlayerUnits(player1);
    }
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

void PlayerVSComputer::placeComputerUnits(Controller& computer) {
    std::cout << "\nPlacing Battlesips\n";
    Game::placeUnits(computer, Helper::unitType::random_battleship, 3);

    // Placing support of player1
    std::cout << "\nPlacing Supports\n";
    Game::placeUnits(computer, Helper::unitType::random_support, 3);

    // Placing submarines of player1
    std::cout << "\nPlacing Submarines\n";
    Game::placeUnits(computer, Helper::unitType::random_submarine, 2);
}

void PlayerVSComputer::placePlayerUnits(Controller& player) {
    std::cout << "\nPlacing Battlesips\n";
    Game::placeUnits(player, Helper::unitType::iBattleship, 3);

    // Placing support of player1
    std::cout << "\nPlacing Supports\n";
    Game::placeUnits(player, Helper::unitType::iSupport, 3);

    // Placing submarines of player1
    std::cout << "\nPlacing Submarines\n";
    Game::placeUnits(player, Helper::unitType::iSubmarine, 2);
}

std::ostream& operator<<(std::ostream& os, PlayerVSComputer& a) {
    // Helper::writeLog(os,a.getLog());

    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream& operator<<(std::ostream& os, PlayerVSComputer* a) {
    os << *a;
    return os;
}
