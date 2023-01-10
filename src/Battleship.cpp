#include "Battleship.h"

Battleship::Battleship(const Position& iBow, const Position& iStern) : Unit(iBow, iStern, 5, 5, 'C'){};
// Riceve un vettore di puntatori a Units lungo 1 se a target il controller avversario ha trovato una nave
std::vector<Entity> Battleship::action(Position iTarget, std::vector<Unit*> iUnits) {
    if (iUnits[0]) {
        // std::cout << iUnits[0]->getId();
        iUnits[0]->updateStatus(iTarget, iUnits[0]->getId());  // il +32 la rende minuscola
        iUnits[0]->setArmor(iUnits[0]->getArmor() - 1);        // TODO: aggiungere lancio eccenzione in caso sia già a zero

        Entity result(iTarget, 'X');
        std::vector<Entity> resultVect;
        resultVect.push_back(result);
        return resultVect;
    }
    Entity result(iTarget, 'O');
    std::vector<Entity> resultVect;
    resultVect.push_back(result);
    return resultVect;
}

Battleship::~Battleship() {
}
