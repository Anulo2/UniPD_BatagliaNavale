#include "Unit.h"

Unit::Unit(Grid::Position i_bow, Grid::Position i_stern): bow{i_bow}, stern{i_stern} {};

Grid::Position Unit::getPosition(void){
    if(isVertical())
        return Grid::Position(stern.x, (stern.y+bow.y)/2);
    else
        return Grid::Position((stern.x+bow.x)/2, stern.y);
}

bool Unit::isVertical(){
    if(stern.x==bow.x)
        return true;
    return false;
}

