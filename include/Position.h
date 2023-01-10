#ifndef POSITION_H
#define POSITION_H

#include <ostream>
#include <iostream>

// A = 0 ... N = 11
static const char rows[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};

class Position {
   public:
    Position();
    Position(const int &iX, const char &iY);
    Position(int iX, int iY);
    char getY() const;
    int getX() const;
    int getIntY() const;
    bool isInside(Position a, Position b);
    bool isAligned(const Position &a) const;
    int distanceTo(const Position &a) const;
    bool isSmaller(const Position &a) const;

    ~Position();

   private:
    int x;
    int y;
};

bool operator==(Position a, Position b);
bool operator!=(Position a, Position b);

std::ostream &operator<<(std::ostream &os, Position a);
std::ostream &operator<<(std::ostream &os, Position *a);

#endif