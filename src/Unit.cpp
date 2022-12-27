

#include "Unit.h"

Unit::Unit(Grid::Position i_bow, Grid::Position i_stern, Controller * i_myController, Controller * i_enemyController){
    middle = Grid::Position((i_bow.x + i_stern.x)/2,(i_bow.y + i_stern.y)/2);
    vertical = i_bow.x == i_stern.x ? true: false; 
    myController = i_myController;
    enemyController = i_enemyController;
};


Grid::Position Unit::getPosition(void){
    return middle;
}

bool Unit::isVertical(){
    return vertical;
}

bool Unit::isInside(Grid::Position in_pos){
    int dim_buff = dimension/2;
    return vertical ? (in_pos.y <= middle.y+dim_buff && in_pos.y >=middle.y-dim_buff):(in_pos.x <= middle.x+dim_buff && in_pos.x >= middle.x-dim_buff); 
}