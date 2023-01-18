// Eris Sanson

#include "Battleship.h"

Battleship::Battleship(const Position &iBow, const Position &iStern)
    : Unit(iBow, iStern, 5, 5, 'C'){};
// Riceve un vettore di puntatori a Units lungo 1 se a target il controller
// avversario ha trovato una nave
std::vector<std::shared_ptr<Entity>> Battleship::action(
    Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits) {
    if (iUnits[0]) {
        // std::cout << iUnits[0] << "\n";
        // std::cout << iUnits[0]->getId();
        if (!iUnits[0]->isHitAt(iTarget)) {
            iUnits[0]->updateStatus(iTarget, true);
            iUnits[0]->setArmor(iUnits[0]->getArmor() - 1);

            Entity result(iTarget, 'X');
            std::vector<std::shared_ptr<Entity>> resultVect;
            resultVect.push_back(std::shared_ptr<Entity>(new Entity(iTarget, 'X')));
            return resultVect;
        }
    }
    Entity result(iTarget, 'O');
    std::vector<std::shared_ptr<Entity>> resultVect;
    resultVect.push_back(std::shared_ptr<Entity>(new Entity(iTarget, 'O')));
    return resultVect;
}

Battleship::~Battleship() {}
