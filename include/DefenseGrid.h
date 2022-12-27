#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include "Grid.h"

class DefenseGrid : public Grid{
    public:
        DefenseGrid();
        bool isValidChar(const char& v);
    
    protected:
        char validChars[3] {'C','S','E'};
};

#endif