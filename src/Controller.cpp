#include "Controller.h"

Controller::Controller() {}

bool Controller::isUnit(Position iPos) {
    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).containsPos(iPos)) {
            return true;
        }
    }
    return false;
}

std::vector<Unit*> Controller::getUnits() {
    return units;
}

Unit* Controller::getUnit(Position iPos) {
    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).containsPos(iPos)) {
            return units.at(i);
        }
    }
    return nullptr;
}

std::vector<Unit*> Controller::getUnitsInRange(Position iPos, int range) {
    std::vector<Unit*> unitsInRange;

    Position a(iPos.getX() - range, iPos.getIntY() - range);
    Position b(iPos.getX() + range, iPos.getIntY() + range);

    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).getBow().isInside(a, b) || (*units[i]).getStern().isInside(a, b)) {
            unitsInRange.push_back(units[i]);
        }
    }

    return unitsInRange;
}

void Controller::addUnit(Unit* iUnit) {
    units.push_back(iUnit);
}

Controller::~Controller() {
}