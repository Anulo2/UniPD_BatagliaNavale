// Eris Sanson

#include "Replay.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/

Replay::Replay(std::vector<std::string> in) {
    placeInOrder(player1, player2, in);
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/
void Replay::placeInOrder(Controller &first, Controller &second, std::vector<std::string> inVect) {
    placeUnitsFor(first, inVect);
    placeUnitsFor(second, inVect);
}

void Replay::placeUnitsFor(Controller &player, std::vector<std::string> inVect) {
    static int iterator = 0;
    for (int i = 0; i < 3; i++) {
        placeUnit(player, Helper::unitType::iBattleship, inVect[iterator++]);
    }

    for (int i = 0; i < 3; i++) {
        placeUnit(player, Helper::unitType::iSupport, inVect[iterator++]);
    }

    for (int i = 0; i < 2; i++) {
        placeUnit(player, Helper::unitType::iSubmarine, inVect[iterator++]);
    }
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
