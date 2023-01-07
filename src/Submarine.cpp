
#include "Submarine.h"

Submarine::Submarine(Position iBow, Position iStern) : Unit(iBow, iStern, 1, 1, 'E'){};

std::vector<Entity> Submarine::action(Position iTarget, std::vector<Unit *> iUnits) {
    middlePos = iTarget;

    std::vector<Position> positionsToCheck;

    for (std::size_t i = 0; i < 5; ++i) {
        for (std::size_t j = 0; j < 5; ++j) {
            if (i == 2 && j == 2) {
                continue;
            }
            positionsToCheck.push_back(Position(middlePos.getX() + (int)(j - 2), middlePos.getIntY() + (int)(i - 2)));
        }
    }

    std::vector<Entity> resultVect;

    for (std::size_t i = 0; i < iUnits.size(); ++i) {
        for (std::size_t j = 0; j < positionsToCheck.size(); j++) {
            if ((*iUnits[i]).isInside(positionsToCheck[j])) {
                Entity result(positionsToCheck[j], 'Y');
                resultVect.push_back(result);
            }
            positionsToCheck.erase(positionsToCheck.begin() + j);
        }
    }

    return resultVect;
}

Submarine::~Submarine() {
}