#include "Position.h"

#include <cctype>

Position::Position() {
    x = 0;
    y = 0;
}

Position::Position(const int& iX, const char& iY) {
    // TODO: CONTROLLI INPUT
    x = iX;

    int tempY = (int)tolower(iY) + 1;

    // bisogna saltare le lettere j e k dell'alfabeto
    (tempY < 106) ? (y = tempY - 97) : (y = tempY - 97);

    
}

// x[0,11] y[0,11]
Position::Position(int iX, int iY) {
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