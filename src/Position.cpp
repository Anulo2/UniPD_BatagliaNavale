#include "Position.h"

Position::Position() {
    x = 0;
    y = 0;
}

Position::Position(const int& iX, const char& iY) {
    if(iX < 1 || iX > 12)
        throw std::invalid_argument("invalid X, valid value for X: [1,2,3,4,5,6,7,8,9,10,11,12]");
    
    if((tolower(iY) < 'a' || tolower(iY) > 'n') || tolower(iY)  == 'j' || tolower(iY) == 'k') 
        throw std::invalid_argument("invalid Y, valid value for Y: [a,b,c,d,e,f,g,h,i,l,m,n]");
    
    x = iX;

    int tempY = (int)tolower(iY);
    std::cout << "tempY:\t" << tempY;
    // bisogna saltare le lettere j e k dell'alfabeto
    (tempY < 106) ? (y = tempY - 96) : (y = tempY - 98);

    //std::cout << "TEMPY : -> " << this->y <<std::endl;
}

//X[1,12] Y[1,12]
Position::Position(int iX, int iY) {
    if ((iX < 1) || (iX > 12) || (iY < 1) || (iY > 12))
       throw std::invalid_argument("invalid X & Y, valid value for X & Y[1,2,3,4,5,6,7,8,9,10,11,12]" );

    // TODO controllare eccezione !!

    x = iX;
    y = iY;
}
char Position::getY() const {
    return rows[y - 1];
}

int Position::getIntY() const {
    return y;
}

int Position::getX() const {
    return x;
}

bool Position::isAligned(const Position& a) const {
    return (x == a.getX() || y == a.getIntY());
}

int Position::distanceTo(const Position& a) const {
    if (!Position::isAligned(a)) {
        throw std::invalid_argument("Positions must be aligned");
    }
    return std::abs(x - a.x) + std::abs(y - a.y);
}

bool Position::isSmaller(const Position& a) const {
    return x < a.x || (x == a.x && y < a.y);
}

bool Position::isInside(Position a, Position b) {
    int x1 = std::min(a.getX(), b.getX());
    int x2 = std::max(a.getX(), b.getX());
    int y1 = std::min(a.getIntY(), b.getIntY());
    int y2 = std::max(a.getIntY(), b.getIntY());

    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
        return true;
    }
    return false;
}

bool operator==(Position a, Position b) {
    return (a.getX() == b.getX()) && (a.getIntY() == b.getIntY());
}

bool operator!=(Position a, Position b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, Position a) {
    os << "(" << a.getX() << ", " << a.getY() << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, Position* a) {
    os << *a;
    return os;
}
Position::~Position() {
}