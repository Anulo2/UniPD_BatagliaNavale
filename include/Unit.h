#ifndef UNIT_H
#define UNIT_H

#include "Grid.h"
#include "Controller.h"

class Unit{
    public:

        Unit(Grid::Position i_bow, Grid::Position i_stern, Controller * i_myController, Controller * i_enemyController);
        Grid::Position getPosition(void); //restiuisce posizione centrale
        virtual void action(Grid::Position x)=0; //funzione virtuale pura 
        virtual char identifier(void)=0; //virtuale pura, restituisce il tipo della nave
        bool isInside(Grid::Position x); //Controlla se una certa posizione è parte di questa nave 
        bool isVertical(); //restituisce true se è verticale false se orizzontale 

    protected:
        Grid::Position middle;
        static const int dimension;
        bool vertical;
        int armor;
        Controller *myController;;
        Controller *enemyController;
        // COntroller giocatore avversario
        // COntroller tuo
        
};

#endif