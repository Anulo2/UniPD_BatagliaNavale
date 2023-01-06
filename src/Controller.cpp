#include "Controller.h"

Controller::Controller(){}

bool Controller::isUnit(Position iPos){
    for(int i = 0; i < units.size(); i++){
        if (units[i].isInside(iPos)){
            return true;
        }
    }
    return false;
}

std::vector<Unit>* Controller::getUnits(){
    return &units;
}

Unit* Controller::getUnit(Position iPos){
    for(int i = 0; i < units.size(); i++){
        if(units[i].getMiddle() == iPos){
            return &units[i];
        }
    }
    return nullptr;
}

std::vector<Unit*> Controller::getUnitsInRange(Position iPos, int range){

    std::vector<Unit*> unitsInRange;

    Position a(iPos.getX() - range/2, iPos.getIntY() - range/2);
    Position b(iPos.getX() + range/2, iPos.getIntY() + range/2);

    for(int i = 0; i < units.size(); i++){
        if(units[i].getBow().isInside(a,b) || units[i].getStern().isInside(a,b)){
            unitsInRange.push_back(&units[i]);
        }
    }

    return unitsInRange;
    /*
    pos a = pos(ipos.x - range/2, ipos.y - range/2) // nel costruttore di pos limitare il valore a 0 e a 11
    pos b = pos(ipos.x + range/2, ipos.y + range/2)
    
    unitatrovate
    for unit in units:
        if unita.bow().is_inside(pos a, pos b) or unit.stern().is_inside(pos a, pos b){ //delimitante l'area
            unitaTrovate.append(unit)
        }

    */

}

void Controller::addUnit(Unit& iUnit){
    units.push_back(iUnit);
}