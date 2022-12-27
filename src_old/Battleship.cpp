#include "Battleship.h"

Battleship::Battleship(Grid::Position i_bow, Grid::Position i_stern) : Unit(i_bow, i_stern) {};

char Battleship::identifier(void){
    return noHit;
}

void Battleship::action(Grid::Position x, Defense_Grid enemy_grid){
                        
}