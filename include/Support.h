#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit{

    public:
        Support(Grid::Position i_bow, Grid::Position i_stern, Controller * i_myController, Controller * i_enemyController);
        void action(Grid::Position x);
        char identifier(void);

    private:
        static const int dimension=3;
        int armor = 3;
        static const char id = 'S';
};

#endif