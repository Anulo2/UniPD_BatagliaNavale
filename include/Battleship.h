#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Unit.h"

class Battleship : public Unit{

    public:
        Battleship(Grid::Position i_bow, Grid::Position i_stern);
        void action(Grid::Position x);
        char identifier(void)=0;


    private:
        static const int dimension=5;
        int armor=5;
        static const char noHit = 'C';
        static const char hit = 'c';

};

#endif