#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <memory>
#include <vector>

#include "Entity.h"
#include "Position.h"

class Unit {
   public:
    Unit(const Position &iBow, const Position &iStern, int iDimension, int iArmor, char iId);
    Unit(const Unit &a);
    Position getMiddle();             // restiuisce posizione centrale
    bool isVertical();                // restituisce true se è verticale false se orizzontale
    bool containsPos(Position iPos);  // Controlla se una certa posizione è parte di questa nave
    char getId();
    Position getBow();
    Position getStern();
    void updateStatus(Position iPos, bool iValue);
    void setArmor(int iArmor);
    int getArmor();
    void resetStatus();
    int getDimension();
    bool isHitAt(Position iPos);
    std::vector<bool> getStatus();
    virtual std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits) = 0;  // funzione virtuale pura, restituisce il tipo della nave
    const std::vector<Position> getUnitPositions();
    virtual ~Unit();

   protected:
    Position middlePos;
    int dimension;
    bool vertical;
    int armor;
    std::vector<bool> status;  // TODO: trasformare in vettore di bool
    char id;
};

std::ostream &operator<<(std::ostream &os, Unit &a);
std::ostream &operator<<(std::ostream &os, Unit *a);

bool operator==(const Unit &a, const Unit &b);
bool operator!=(const Unit &a, const Unit &b);

#endif