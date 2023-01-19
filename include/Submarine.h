// Leonardo Canello

#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit {
public:
    Submarine(Position iBow, Position iStern);                                                                // costruttore standard
    Submarine(Position iPos);                                                                                 // costruttore con solo una coordinata
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits); // funzione virtuale di Unit

    ~Submarine(); // distruttore
};

#endif