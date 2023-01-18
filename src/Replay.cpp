// Eris Sanson

#include "Replay.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/

Replay::Replay(std::vector<std::string> in) {
    int iterator = 0;
    static const int nTotalUnitsInGame = 16;

    while (iterator < nTotalUnitsInGame) {
        // Placing battleships of player1

        for (int i = 0; i < 3; i++) {
            placeUnit(player1, Helper::unitType::iBattleship, in[iterator]);
            iterator++;
        }

        // Placing supports of player1
        for (int i = 0; i < 3; i++) {
            placeUnit(player1, Helper::unitType::iSupport, in[iterator]);
            iterator++;
        }

        // Placing submarines of player1
        for (int i = 0; i < 2; i++) {
            placeUnit(player1, Helper::unitType::iSubmarine, in[iterator]);
            iterator++;
        }

        // Placing battleships of player2
        for (int i = 0; i < 3; i++) {
            placeUnit(player2, Helper::unitType::iBattleship, in[iterator]);
            iterator++;
        }

        // Placing supports of player2
        for (int i = 0; i < 3; i++) {
            placeUnit(player2, Helper::unitType::iSupport, in[iterator]);
            iterator++;
        }

        // Placing submarines of player2
        for (int i = 0; i < 2; i++) {
            placeUnit(player2, Helper::unitType::iSubmarine, in[iterator]);
            iterator++;
        }

        // end placing unit
    }  // end of while
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

std::ostream &operator<<(std::ostream &os, Replay &a) {
    // Helper::writeLog(os, a.getLog());
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream &operator<<(std::ostream &os, Replay *a) {
    os << *a;
    return os;
}
