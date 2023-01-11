
#include "Submarine.h"

Submarine::Submarine(Position iBow, Position iStern) : Unit(iBow, iStern, 1, 1, 'E'){};
Submarine::Submarine(Position iPos) : Unit(iPos, iPos, 1, 1, 'E'){};
// RIceve un vettore di puntatori a Units con le unità in area 5x5 con centro il submarine
// Il controllo se si può muovere in quella posizione bisogna farlo nel controller del giocatore
// che sta facendo l'azione
std::vector<Entity> Submarine::action(Position iTarget, std::vector<Unit *> iUnits) {
    middlePos = iTarget;

    Position a(std::max(iTarget.getX() - 2, 1), std::max(iTarget.getIntY() - 2, 1));
    Position b(std::min(iTarget.getX() + 2, 12), std::min(iTarget.getIntY() + 2, 12));

    std::cout << a << "\n";
    std::cout << b << "\n";

    std::vector<Entity> resultVect;
    std::cout << "here\n";
    std::cout << iTarget << "\n";

    for (int i = 0; i < iUnits.size(); i++) {
        std::cout << iUnits[i] << "\n";
        if (iUnits[i]->getMiddle() != iTarget) {
            for (int j = 0; j < iUnits[i]->getDimension(); j++) {
                if (iUnits[i]->isVertical()) {
                    Position buffer(Unit::getStern().getX(), (Unit::getStern().getIntY() + j));
                    if (buffer.isInside(a, b)) {
                        if (iUnits[i]->isHitAt(buffer)) {
                            Entity result(buffer, 'X');
                            resultVect.push_back(result);
                        } else {
                            Entity result(buffer, 'Y');
                            resultVect.push_back(result);
                        }
                    }

                } else {
                    Position buffer(Unit::getStern().getX() + j, (Unit::getStern().getIntY()));
                    if (buffer.isInside(a, b)) {
                        if (iUnits[i]->isHitAt(buffer)) {
                            Entity result(buffer, 'X');
                            resultVect.push_back(result);
                        } else {
                            Entity result(buffer, 'Y');
                            resultVect.push_back(result);
                        }
                    }
                }
            }
        }
    }

    /*
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
    }*/

    return resultVect;
}

Submarine::~Submarine() {
}