#ifndef UNIT_H
#define UNIT_H

#include <vector>

#include "Position.h"
#include "Entity.h"

class Unit{
    public:

        Unit(Position iBow, Position iStern);
        Position getMiddle(); //restiuisce posizione centrale
        virtual Entity* action(Position iTarget, Unit * iUnits)=0; //funzione virtuale pura 
        char identifier(); //virtuale pura, restituisce il tipo della nave
        bool isInside(Position iPos); //Controlla se una certa posizione è parte di questa nave 
        bool isVertical(); //restituisce true se è verticale false se orizzontale 
        Position getBow();
        Position getStern();

    protected:
        Position middlePos;
        Position bow;
        Position stern;
        static const int dimension;
        bool vertical;
        int armor;
        std::vector<char> status;
        static const char id;
        
};

#endif