// Leonardo Canello

#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <ostream>

// caratteri validi per le righe
// A = 0 ... N = 11
static const char rows[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};

class Position {
   public:
    // costruttore di default
    Position();

    // costruttore
    Position(const int &iX, const char &iY);
    // costruttore
    Position(int iX, int iY);

    // getter y
    char getY() const;

    // getter valore intero associato a y
    int getIntY() const;

    // getter x
    int getX() const;

    // setter x
    void setX(int iX) { x = iX; };

    // setter y
    void setY(int iY) { y = iY; };

    // true se la posizione è all'interno del rettangolo dato
    bool isInside(Position a, Position b);

    // restituisce se le posizioni sono allineate
    bool isAligned(const Position &a) const;

    // restituisce la distanza tra le posizioni
    int distanceTo(const Position &a) const;

    // restituisce se la posizione è più piccola di quella data
    bool isSmaller(const Position &a) const;

    ~Position();  // distruttore

   private:
    int x;
    int y;
};

// overload operatori
bool operator==(Position a, Position b);
bool operator!=(Position a, Position b);

std::ostream &operator<<(std::ostream &os, Position a);
std::ostream &operator<<(std::ostream &os, Position *a);

#endif