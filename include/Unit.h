#ifndef UNIT_H
#define UNIT_H

#include "Grid.h"

class Unit{
    public:

        Unit(Grid::Position i_bow, Grid::Position i_stern);
        Grid::Position getPosition(void);
        virtual void action(Grid::Position x)=0; //funzione virtuale pura 
        virtual char identifier(void)=0; //virtuale pura

    protected:
        Grid::Position bow; //poppa
        Grid::Position stern; //prua
};

#endif