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
        if ((*units[i]).getBow().isInside(a, b) || (*units[i]).getStern().isInside(a, b)) { //DUBBIO SU VERIFICA: se range = 1 e nave è corazzata può succedere che ne prua ne poppa sono dentro ma qualche altra casella della nave si
            unitsInRange.push_back(units[i]);
        }
    }

    return unitsInRange;
}

bool segments_collide(const Position& p1, const Position& p2, const Position& p3, const Position& p4) {
    // Check if the segments are both horizontal or both vertical
    if ((p1.getX() == p2.getX() && p3.getX() == p4.getX()) || (p1.getIntY() == p2.getIntY() && p3.getIntY() == p4.getIntY())) {
        // Check if the x-coordinates or y-coordinates overlap
        if ((p1.getX() <= p3.getX() && p3.getX() <= p2.getX()) || (p3.getX() <= p1.getX() && p1.getX() <= p4.getX())) {
            return true;
        }
        if ((p1.getIntY() <= p3.getIntY() && p3.getIntY() <= p2.getIntY()) || (p3.getIntY() <= p1.getIntY() && p1.getIntY() <= p4.getIntY())) {
            return true;
        }
    }
    return false;
}

bool Controller::checkUnitPlacement(Unit* iUnit)
{   
    Position a(0,0);
    Position b(12,12);
    if(iUnit->getBow().isInside(a,b) && iUnit->getStern().isInside(a,b)){
        for(int i =0; i < units.size(); i++){
            if(segments_collide(iUnit->getStern(), iUnit->getBow(), (*units[i]).getStern(), (*units[i]).getBow())){
                return false;
            }
        
        }
    }
    return true;
}


void Controller::addUnit(Unit* iUnit) {
    units.push_back(iUnit);
}

Controller::~Controller() {
}