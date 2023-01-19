// Leonardo Canello

#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit {
   public:
    // costruttore standard
    Submarine(Position iBow, Position iStern);

    // costruttore con solo una coordinata
    Submarine(Position iPos);

    // funzione virtuale di Unit
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits);

    ~Submarine();  // distruttore
};

#endif