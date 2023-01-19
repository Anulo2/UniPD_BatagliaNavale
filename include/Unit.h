// Leonardo Canello

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

    // restiuisce posizione centrale
    Position getMiddle() const;

    // restituisce true se è verticale false se orizzontale
    bool isVertical() const;

    // Controlla se una certa posizione è parte di questa nave
    bool containsPos(Position iPos);

    // restituisce il carattere identificativo del tipo di nave
    char getId() const;

    // restituisce la posizione della bow
    Position getBow() const;

    // restituisce la posizione della stern
    Position getStern() const;

    // esegue un update dello status di salute della nave
    void updateStatus(Position iPos, bool iValue);

    // setter dell'armatura
    void setArmor(int iArmor);

    // getter dell'armatura
    int getArmor() const;

    // resetta lo status allo stato inziale
    void resetStatus();

    // getter della dimensione
    int getDimension();

    // restituisce vero o falso in base a se la nave è stata colpita nella data posizione
    bool isHitAt(Position iPos);

    // getter dello status
    std::vector<bool> getStatus();

    // funzione virtuale pura, restituisce il tipo della nave
    virtual std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits) = 0;

    // getter di tutte le posizioni della nave
    std::vector<Position> getUnitPositions() const;

    // distruttore
    virtual ~Unit();

   protected:
    // posizione centrale identificativa
    Position middlePos;

    // dimensione
    int dimension;

    // true se verticale, false se orizzontale
    bool vertical;

    // armatura
    int armor;

    // status identificativo delle caselle colpite e sane dell'unità
    std::vector<bool> status;

    // carattere identificativo del tipo di nave
    char id;
};

// overload operatori
std::ostream &operator<<(std::ostream &os, Unit &a);
std::ostream &operator<<(std::ostream &os, Unit *a);

#endif