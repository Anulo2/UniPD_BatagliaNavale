#ifndef UNIT_H
#define UNIT_H

#include <vector>

#include "Entity.h"
#include "Position.h"

class Unit {
   public:
    Unit(const Position &iBow, const Position &iStern, int iDimension, int iArmor, char iId);
    Position getMiddle();                                                                  // restiuisce posizione centrale
    virtual std::vector<Entity> action(Position iTarget, std::vector<Unit *> iUnits) = 0;  // funzione virtuale
    char getId();                                                                          // virtuale pura, restituisce il tipo della nave
    bool isInside(Position iPos);                                                          // Controlla se una certa posizione è parte di questa nave
    bool isVertical();                                                                     // restituisce true se è verticale false se orizzontale
    Position getBow();
    Position getStern();
    void updateStatus(Position iPos, char iChar);
    void resetStatus();
    int getDimension();

    void setArmor(int iArmor);
    int getArmor();

    virtual ~Unit();

   protected:
    Position middlePos;
    int dimension;
    bool vertical;
    int armor;
    std::vector<char> status;
    char id;
};

#endif