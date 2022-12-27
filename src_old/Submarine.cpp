#include "Submarine.h"

Submarine::Submarine(Grid::Position i_bow, Grid::Position i_stern) : Unit(i_bow, i_stern) {};

char Submarine::identifier(void){
    return noHit;
}

void Submarine::action(Grid::Position x){
                        
}