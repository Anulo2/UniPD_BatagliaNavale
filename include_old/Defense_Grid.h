#ifndef DEFENSE_GRID_H
#define DEFENSE_GRID_H

#include "Grid.h"

class Defense_Grid : public Grid{
    public:
        Defense_Grid();
        bool isValidChar(const char& v);
    
    protected:
        char validChars[6] {'C','S','E'};
};

#endif