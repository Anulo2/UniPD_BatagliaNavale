#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit{

    public:
        Submarine(Grid::Position i_bow, Grid::Position i_stern);
        Submarine(Grid::Position i_pos, Defense_Grid enemy_grid);
        void action(Grid::Position x, Defense_Grid enemy_grid);
        char identifier(void)=0;


    private:
        static const int dimension=1;
        int armor=1;
        static const char noHit = 'E';
        static const char hit = 'e';

};

#endif