#ifndef POSITION_H
#define POSITION_H

#include <ostream>

// A = 0 ... N = 11
static const char rows[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};

class Position {
   public:
    Position();
    Position(const int &iX, const char &iY);
    Position(int iX, int iY);
    Position(char *iPos);
    char getY();
    int getX();
    int getIntY();
    bool isInside(Position a, Position b);

    ~Position();

   private:
    int x;
    int y;
};

bool operator==(Position a, Position b);
bool operator!=(Position a, Position b);

std::ostream &operator<<(std::ostream &os, Position a);

#endif