#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Grid.h"
#include "Unit.h"

class Controller{
    public:
        Controller();
        void addUnit(Unit* unita);
        bool canMove(Unit* unita, Grid::Position dest);
        bool action(Unit* unita, Grid::Position dest);
        

    protected:
       std::vector<Unit*> unita;
       std::vector<Grid*> griglie;
        
};

#endif