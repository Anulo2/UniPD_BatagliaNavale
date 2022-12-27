#include "Support.h"

Support::Support(Grid::Position i_bow, Grid::Position i_stern) : Unit(i_bow, i_stern) {};

char Support::identifier(void){
    return noHit;
}

void Support::action(Grid::Position x){
                        
}