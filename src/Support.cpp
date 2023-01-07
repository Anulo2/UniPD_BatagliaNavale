
#include "Support.h"

Support::Support(Position iBow, Position iStern) : Unit(iBow, iStern, 3, 3, 'S'){};

std::vector<Entity> Support::action(Position iTarget, std::vector<Unit *> iUnits) {
    middlePos = iTarget;  // il controllo se si può muovere qua bisogna farlo in controller

    std::vector<Position> positionsToCheck;

    if (vertical) {
        positionsToCheck.push_back(Position(middlePos.getX() - 1, middlePos.getIntY() - 1));
        positionsToCheck.push_back(Position(middlePos.getX() - 1, middlePos.getIntY()));
        positionsToCheck.push_back(Position(middlePos.getX() - 1, middlePos.getIntY() + 1));
        positionsToCheck.push_back(Position(middlePos.getX() + 1, middlePos.getIntY() - 1));
        positionsToCheck.push_back(Position(middlePos.getX() + 1, middlePos.getIntY()));
        positionsToCheck.push_back(Position(middlePos.getX() + 1, middlePos.getIntY() + 1));
    } else {
        positionsToCheck.push_back(Position(middlePos.getX() - 1, middlePos.getIntY() - 1));
        positionsToCheck.push_back(Position(middlePos.getX(), middlePos.getIntY() - 1));
        positionsToCheck.push_back(Position(middlePos.getX() + 1, middlePos.getIntY() - 1));
        positionsToCheck.push_back(Position(middlePos.getX() - 1, middlePos.getIntY() + 1));
        positionsToCheck.push_back(Position(middlePos.getX(), middlePos.getIntY() + 1));
        positionsToCheck.push_back(Position(middlePos.getX() + 1, middlePos.getIntY() + 1));
    }

    for (std::size_t i = 0; i < iUnits.size(); ++i) {
        for (std::size_t j = 0; j < positionsToCheck.size(); j++) {
            if ((*iUnits[i]).isInside(positionsToCheck[j])) {
                (*iUnits[i]).setArmor((*iUnits[i]).getDimension());
                break;
            }
            positionsToCheck.erase(positionsToCheck.begin() + j);
        }
    }
    std::vector<Entity> resultVect;
    return resultVect;
}

Support::~Support() {
}