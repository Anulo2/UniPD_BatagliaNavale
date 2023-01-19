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
    Position getMiddle() const;                                                                                           // restiuisce posizione centrale
    bool isVertical() const;                                                                                              // restituisce true se è verticale false se orizzontale
    bool containsPos(Position iPos);                                                                                      // Controlla se una certa posizione è parte di questa nave
    char getId() const;                                                                                                   // restituisce il carattere identificativo del tipo di nave
    Position getBow() const;                                                                                              // restituisce la posizione della bow
    Position getStern() const;                                                                                            // restituisce la posizione della stern
    void updateStatus(Position iPos, bool iValue);                                                                        // esegue un update dello status di salute della nave
    void setArmor(int iArmor);                                                                                            // setter dell'armatura
    int getArmor() const;                                                                                                 // getter dell'armatura
    void resetStatus();                                                                                                   // resetta lo status allo stato inziale
    int getDimension();                                                                                                   // getter della dimensione
    bool isHitAt(Position iPos);                                                                                          // restituisce vero o falso in base a se la nave è stata colpita nella data posizione
    std::vector<bool> getStatus();                                                                                        // getter dello status
    virtual std::vector<std::shared_ptr<Entity>> action(Position iTarget, std::vector<std::shared_ptr<Unit>> iUnits) = 0; // funzione virtuale pura, restituisce il tipo della nave
    std::vector<Position> getUnitPositions() const;                                                                       // getter di tutte le posizioni della nave
    virtual ~Unit();                                                                                                      // distruttore

protected:
    Position middlePos;       // posizione centrale identificativa
    int dimension;            // dimensione
    bool vertical;            // true se verticale, false se orizzontale
    int armor;                // armatura
    std::vector<bool> status; // status identificativo delle caselle colpite e sane dell'unità
    char id;                  // carattere identificativo del tipo di nave
};

// overload operatori
std::ostream &operator<<(std::ostream &os, Unit &a);
std::ostream &operator<<(std::ostream &os, Unit *a);

#endif