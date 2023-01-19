// Enrico Zanoni

#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit {
public:
    Support(const Position &iBow, const Position &iStern);                                                           // costruttore standard
    std::vector<std::shared_ptr<Entity>> action(const Position &iTarget, std::vector<std::shared_ptr<Unit>> iUnits); // funzione virtuale di Unit

    ~Support(); // distruttore
};

#endif