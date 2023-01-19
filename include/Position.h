// Leonardo Canello

#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <ostream>

// A = 0 ... N = 11
static const char rows[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'}; // caratteri validi per le righe

class Position {
public:
    Position();                              // costruttore di default
    Position(const int &iX, const char &iY); // costruttore
    Position(int iX, int iY);                // costruttore
    char getY() const;                       // getter y
    int getX() const;                        // getter x
    int getIntY() const;                     // getter valore intero associato a y
    void setX(int iX) { x = iX; };           // setter x
    void setY(int iY) { y = iY; };           // setter y
    bool isInside(Position a, Position b);   // true se la posizione è all'interno del rettangolo dato
    bool isAligned(const Position &a) const; // restituisce se le posizioni sono allineate
    int distanceTo(const Position &a) const; // restituisce la distanza tra le posizioni
    bool isSmaller(const Position &a) const; // restituisce se la posizione è più piccola di quella data

    ~Position(); // distruttore

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