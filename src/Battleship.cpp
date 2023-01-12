#include "Battleship.h"

Battleship::Battleship(const Position& iBow, const Position& iStern) : Unit(iBow, iStern, 5, 5, 'C'){};
// Riceve un vettore di puntatori a Units lungo 1 se a target il controller avversario ha trovato una nave
std::vector<std::shared_ptr<Entity>> Battleship::action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits) {
    if (iUnits[0]) {
        // std::cout << iUnits[0] << "\n";
        // std::cout << iUnits[0]->getId();
        iUnits[0]->updateStatus(iTarget, true);          // il +32 la rende minuscola
        iUnits[0]->setArmor(iUnits[0]->getArmor() - 1);  // TODO: aggiungere lancio eccenzione in caso sia già a zero

        Entity result(iTarget, 'X');
        std::vector<std::shared_ptr<Entity>> resultVect;
        resultVect.push_back(std::shared_ptr<Entity>(new Entity(iTarget, 'X')));
        return resultVect;
    }
    Entity result(iTarget, 'O');
    std::vector<std::shared_ptr<Entity>> resultVect;
    resultVect.push_back(std::shared_ptr<Entity>(new Entity(iTarget, 'O')));
    return resultVect;
}

Battleship::~Battleship() {
}
