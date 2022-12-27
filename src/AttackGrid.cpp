#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include "Grid.h"

class AttackGrid : public Grid{
    public:
        AttackGrid();
        bool isValidChar(const char& v);

    protected:
        char validChars[3] {'O', 'X' , 'Y'};
};

#endif