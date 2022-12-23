#ifndef SUPPORT_H
#define SUPPORT_H

#include "Unit.h"

class Support : public Unit{

    public:
        Support(Grid::Position i_bow, Grid::Position i_stern);
        void action(Grid::Position x);
        char identifier(void)=0;

    private:
        static const int dimension=3;
        int armor=3;
        static const char noHit = 'S';
        static const char hit = 's';

};

#endif