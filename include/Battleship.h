// Eris Sanson

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Unit.h"

class Battleship : public Unit {
public:
    Battleship(const Position &iBow, const Position &iStern);                                                 // costruttore standard
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits); // funzione virtuale di Unit

    ~Battleship(); // distruttore
};

#endif