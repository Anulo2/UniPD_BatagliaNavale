#include "Position.h"
#include <cctype>

Position::Position(){
    x = 0;
    y = 0;
}

Position::Position(const int & iX, const char & iY){
    x = iX;
    y = (int)tolower(iY) - 48; // a, A
};

char Position::getY(){
    return rows[y];
}

int Position::getIntY(){
    return y;
}

int Position::getX(){
    return x;
}

bool Position::isInside(Position a, Position b){
    if (x > a.getX() and x < b.getX() and y > a.getIntY() and y < b.getIntY()){
        return true;
    }
    return false;
}

bool operator==(Position a, Position b) {
    return (a.getX() == b.getX()) && (a.getIntY() == b.getIntY());
}

bool operator!=(Position a, Position b) {
    return (a.getX() != b.getX()) || (a.getIntY() != b.getIntY());
}