// Eris Sanson

#include "Replay.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/

Replay::Replay(std::vector<std::string> in) {
    static const int nTotalUnitsInGame = 16;

    // Placing battleships of player1
    while (!placeUnitsFor(player1, in)) {
        std::cout << "Placing player1 unis\n";
    }

    while (!placeUnitsFor(player2, in)) {
        std::cout << "Placing player2 unis\n";
    }
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

bool Replay::placeUnitsFor(Controller &player, std::vector<std::string> inString) {
    static int iterator = 0;
    for (int i = 0; i < 3; i++) {
        placeUnit(player, Helper::unitType::iBattleship, inString[iterator++]);
    }

    for (int i = 0; i < 3; i++) {
        placeUnit(player, Helper::unitType::iSupport, inString[iterator++]);
    }

    for (int i = 0; i < 2; i++) {
        placeUnit(player, Helper::unitType::iSubmarine, inString[iterator++]);
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, Replay &a) {
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream &operator<<(std::ostream &os, Replay *a) {
    os << *a;
    return os;
}
