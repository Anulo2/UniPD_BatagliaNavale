#include "Battleship.h"

Battleship::Battleship(const Position& iBow, const Position& iStern) : Unit(iBow, iStern, 5, 5, 'C'){};

std::vector<Entity> Battleship::action(Position iTarget, std::vector<Unit*> iUnits) {
    for (std::size_t i = 0; i < iUnits.size(); ++i) {
        if ((*iUnits[i]).isInside(iTarget)) {
            (*iUnits[i]).updateStatus(iTarget, (*iUnits[i]).getId() + 32);  // il +32 la rende minuscola
            (*iUnits[i]).setArmor((*iUnits[i]).getArmor() - 1);             // TODO: aggiungere lancio eccenzione in caso sia già a zero
            Entity result(iTarget, 'X');
            std::vector<Entity> resultVect;
            resultVect.push_back(result);
            return resultVect;
        }
    }
    Entity result(iTarget, 'O');
    std::vector<Entity> resultVect;
    resultVect.push_back(result);
    return resultVect;
}

Battleship::~Battleship() {
}