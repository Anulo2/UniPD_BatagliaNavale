#ifndef UNIT_H
#define UNIT_H

#include <vector>

#include "Entity.h"
#include "Position.h"

class Unit {
   public:
    Unit(const Position &iBow, const Position &iStern);
    Position getMiddle();                                        // restiuisce posizione centrale
    virtual Entity *action(Position iTarget, Unit *iUnits) = 0;  // funzione virtuale
    char getId();                                                // virtuale pura, restituisce il tipo della nave
    bool isInside(Position iPos);                                // Controlla se una certa posizione è parte di questa nave
    bool isVertical();                                           // restituisce true se è verticale false se orizzontale
    Position getBow();
    Position getStern();

    virtual ~Unit();

   protected:
    Position middlePos;
    Position bow;
    Position stern;
    static const int dimension = 1;
    bool vertical;
    int armor;
    std::vector<char> status = {};
    static const char id = ' ';
};

#endif