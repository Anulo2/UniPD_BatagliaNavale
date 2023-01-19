// Eris Sanson

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Unit.h"

class Battleship : public Unit {
   public:
    // costruttore standard
    Battleship(const Position &iBow, const Position &iStern);

    // funzione virtuale di Unit
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits);

    // distruttore
    ~Battleship();
};

#endif