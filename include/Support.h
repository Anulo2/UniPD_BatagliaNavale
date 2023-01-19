// Enrico Zanoni

#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit {
public:
    Support(Position iBow, Position iStern);                                                                  // costruttore standard 
    std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits); // funzione virtuale di Unit

    ~Support(); // distruttore
};

#endif