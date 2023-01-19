// Leonardo Canello

#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit {
public:
    // costruttore standard
    Submarine(const Position &iBow, const Position &iStern);

    // costruttore con solo una coordinata
    Submarine(const Position &iPos);

    // funzione virtuale di Unit
    std::vector<std::shared_ptr<Entity>> action(const Position &iTarget, std::vector<std::shared_ptr<Unit>> iUnits);

    ~Submarine(); // distruttore
};

#endif