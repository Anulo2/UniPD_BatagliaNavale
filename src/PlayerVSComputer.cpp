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

void PlayerVSComputer::placeComputerUnits(Controller &computer) {
    std::cout << "\n### Placing Battlesips ###\n";

    Game::placeUnits(computer, Helper::unitType::random_battleship, 3);

    // Placing support of player1
    std::cout << "\n### Placing Supports ###\n";
    Game::placeUnits(computer, Helper::unitType::random_support, 3);

    // Placing submarines of player1
    std::cout << "\n### Placing Submarines ###\n";
    Game::placeUnits(computer, Helper::unitType::random_submarine, 2);
}

void PlayerVSComputer::placePlayerUnits(Controller &player) {
    // Placing Battleship of player
    std::cout << "\nSet next unit bow and stern position\n";
    std::cout << "Example: A1 A5" << std::endl;

    std::cout << "\n### Placing 3 Battlesips ###\n";
    std::cout << "\n### This unit has dimension = 5 ###\n";
    std::cout << "\n-> ";
    Game::placeUnits(player, Helper::unitType::iBattleship, 3);

    // Placing support of player
    std::cout << "\nSet next unit bow and stern position\n";
    std::cout << "Example: A6 C6" << std::endl;

    std::cout << "\n### Placing 3 Supports ###\n";
    std::cout << "\n### This unit has dimension = 3 ###\n";

    std::cout << "\n-> ";
    Game::placeUnits(player, Helper::unitType::iSupport, 3);

    // Placing submarines of player
    std::cout << "\nSet next unit bow and stern position\n";
    std::cout << "Example: H11 H11" << std::endl;

    std::cout << "\n### Placing 2 Submarines ###\n";
    std::cout << "\n### This unit has dimension = 1 ###\n";
    std::cout << "\n-> ";
    Game::placeUnits(player, Helper::unitType::iSubmarine, 2);
}

std::ostream &operator<<(std::ostream &os, PlayerVSComputer &a) {
    // Helper::writeLog(os,a.getLog());

    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream &operator<<(std::ostream &os, PlayerVSComputer *a) {
    os << *a;
    return os;
}
