// Enrico Zanoni

#include "ComputerVSComputer.h"

ComputerVSComputer::ComputerVSComputer() {
}

void ComputerVSComputer::startGame() {
    Game::startGame();

    if (selectPlayer == 0) {
        placeInOrder(player1, player2);
    } else {
        placeInOrder(player2, player1);
    }
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/
void ComputerVSComputer::placeInOrder(Controller &first, Controller &second) {
    placeUnitsFor(first);
    placeUnitsFor(second);
}

void ComputerVSComputer::placeUnitsFor(Controller &player) {
    std::cout << "\nPlacing Battlesips\n";
    Game::placeUnits(player, Helper::unitType::random_battleship, 3);

    // Placing support of player1
    std::cout << "\nPlacing Supports\n";
    Game::placeUnits(player, Helper::unitType::random_support, 3);

    // Placing submarines of player1
    std::cout << "\nPlacing Submarines\n";
    Game::placeUnits(player, Helper::unitType::random_submarine, 2);
}

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
