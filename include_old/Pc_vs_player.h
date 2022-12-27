#ifndef PC_VS_PLAYER_H
#define PC_VS_PLAYER_H

#include "Game.h"

class Pc_vs_player : public Game{

    public:
        Pc_vs_player();
        void setUnits(); //pc random e player input da terminale

        void visualize(); //per gestire il comando speciale XX XX (possibile solo nelle partite con un player)

};

#endif