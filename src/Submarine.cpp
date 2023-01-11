
#include "Submarine.h"

Submarine::Submarine(Position iBow, Position iStern) : Unit(iBow, iStern, 1, 1, 'E'){};
Submarine::Submarine(Position iPos) : Unit(iPos, iPos, 1, 1, 'E'){};
// RIceve un vettore di puntatori a Units con le unità in area 5x5 con centro il submarine
// Il controllo se si può muovere in quella posizione bisogna farlo nel controller del giocatore
// che sta facendo l'azione
std::vector<Entity> Submarine::action(Position iTarget, std::vector<Unit *> iUnits) {
    middlePos = iTarget;

    Position a(iTarget.getX() - 2, iTarget.getIntY() - 2);
    Position b(iTarget.getX() + 2, iTarget.getIntY() + 2);

    std::vector<Entity> resultVect;

    for (std::size_t i = 0; i < iUnits.size(); ++i) {
        std::vector<Position> unitPositions = (*iUnits[i]).getUnitPositions();

        for (std::size_t j = 0; j < unitPositions.size(); ++j) {
            if (unitPositions[j].isInside(a, b)) {
                
                if(iUnits[i]-> isHitAt(unitPositions[j])){
Entity result(unitPositions[j], 'X');
                resultVect.push_back(result);
                }else{
Entity result(unitPositions[j], 'Y');
                resultVect.push_back(result);
                }
                
            }
        }
    }

    return resultVect;
}

Submarine::~Submarine() {
}