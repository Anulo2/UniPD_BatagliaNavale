#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Unit.h"

class Submarine : public Unit{

    public:
        Submarine(Grid::Position i_bow, Grid::Position i_stern);
        void action(Grid::Position x);
        char identifier(void)=0;


    private:
        static const int dimension=1;
        int armor=1;
        static const char noHit = 'E';
        static const char hit = 'e';

};

#endif