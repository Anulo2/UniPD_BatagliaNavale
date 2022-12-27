
#include "Support.h"

Support::Support(Grid::Position i_bow, Grid::Position i_stern, Controller * i_myController, Controller * i_enemyController) : Unit(i_bow, i_stern, i_myController, i_enemyController) {};

char Support::identifier(void){
    return id;
}

void Support::action(Grid::Position x){
                  
}