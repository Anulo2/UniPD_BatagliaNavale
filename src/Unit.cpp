// Leonardo Canello

#include "Unit.h"

Unit::Unit(const Position &iBow, const Position &iStern, const int &iDimension, const int &iArmor, const char &iId) {
    Position bow(iBow);
    Position stern(iStern);

    if (!bow.isAligned(stern)) {
        throw std::invalid_argument("Positions must be aligned \n");
    }
    if ((bow.distanceTo(stern) + 1) != iDimension) {
        throw std::invalid_argument("These positions do not rapresent that Unit \n");
    }
    for (std::size_t i = 0; i < iDimension; ++i) {
        status.push_back(false);
    }
    middlePos = Position((bow.getX() + stern.getX()) / 2, (bow.getIntY() + stern.getIntY()) / 2);
    vertical = (bow.getX() == stern.getX()) ? true : false;
    dimension = iDimension;
    armor = iArmor;
    id = iId;
};

Unit::Unit(const Unit &a) {
    middlePos = a.middlePos;
    vertical = a.vertical;
    dimension = a.dimension;
    armor = a.armor;
    id = a.id;
    status = a.status;
}

bool Unit::isHitAt(const Position &iPos) {
    if (Unit::containsPos(iPos)) {
        if (vertical) {
            return status[iPos.getIntY() - Unit::getStern().getIntY()];
            // return status[dimension - (Unit::getBow().getIntY() - iPos.getIntY()) - 1];
        } else {
            return status[iPos.getX() - Unit::getStern().getX()];
        }
    }
    return false;
}

Position Unit::getMiddle() const {
    return middlePos;
}

bool Unit::isVertical() const {
    return vertical;
}

bool Unit::containsPos(const Position &iPos) {
    return iPos.isInside(Unit::getStern(), Unit::getBow());
}

char Unit::getId() const {
    return id;
}

Position Unit::getBow() const {
    if (vertical) {
        return Position(middlePos.getX(), middlePos.getIntY() + dimension / 2);
    } else {
        return Position(middlePos.getX() + dimension / 2, middlePos.getIntY());
    }
}

Position Unit::getStern() const {
    if (vertical) {
        return Position(middlePos.getX(), middlePos.getIntY() - (dimension / 2));
    } else {
        return Position(middlePos.getX() - (dimension / 2), middlePos.getIntY());
    }
}

void Unit::updateStatus(const Position &iPos, const bool &iValue) {
    if (Unit::containsPos(iPos)) {
        if (vertical) {
            status[iPos.getIntY() - Unit::getStern().getIntY()] = iValue;
            // status[dimension - (Unit::getBow().getIntY() - iPos.getIntY()) - 1] = iValue;
        } else {
            status[iPos.getX() - Unit::getStern().getX()] = iValue;
        }
    }
}

void Unit::setArmor(const int &iArmor) {
    armor = iArmor;
}

int Unit::getArmor() const {
    return armor;
}

void Unit::resetStatus() {
    for (int i = 0; i < dimension; i++) {
        status[i] = false;
    }
}

int Unit::getDimension() {
    return dimension;
}

std::vector<bool> Unit::getStatus() {
    return status;
}

std::vector<Position> Unit::getUnitPositions() const {
    std::vector<Position> result;
    if (vertical) {
        for (int i = 0; i < dimension; i++) {
            Position buffer(Unit::getStern().getX(), (int)(Unit::getStern().getIntY() + i));
            result.push_back(buffer);
        }
    } else {
        for (int i = 0; i < dimension; i++) {
            Position buffer(Unit::getStern().getX() + i, (int)(Unit::getStern().getIntY()));
            result.push_back(buffer);
        }
    }
    return result;
}

Unit::~Unit() {
}

std::ostream &operator<<(std::ostream &os, Unit &a) {
    std::string status;
    for (bool c : a.getStatus()) {
        status.push_back(c ? (a.getId() + 32) : a.getId());
    }
    os << "(Pos: " << a.getMiddle() << ", Dim: " << a.getDimension();
    os << ", Vert: " << a.isVertical() << ", Armor: " << a.getArmor() << ", Status: " << status << ", Id: " << a.getId() << ")";
    return os;
}
std::ostream &operator<<(std::ostream &os, Unit *a) {
    os << *a;
    return os;
}
