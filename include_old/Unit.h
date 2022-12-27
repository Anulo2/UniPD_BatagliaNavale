#ifndef UNIT_H
#define UNIT_H

#include "Grid.h"
#include "Defense_Grid.h"

class Unit{
    public:

        Unit(Grid::Position i_bow, Grid::Position i_stern);
        Grid::Position getPosition(void); //restiuisce posizione centrale
        virtual void action(Grid::Position x, Defense_Grid enemy_grid)=0; //funzione virtuale pura 
        virtual char identifier(void)=0; //virtuale pura
        bool isVertical(); //restituisce true se è verticale false se orizzontale
        virtual bool canMove()=0; // true se è viva, false se è morta

    protected:
        Grid::Position bow; //poppa
        Grid::Position stern; //prua

        // COntroller giocatore avversario
        // COntroller tuo
        
};

#endif