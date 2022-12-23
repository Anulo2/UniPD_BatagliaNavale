#ifndef GAME_H
#define GAME_H

#include "Defense_Grid.h"
#include "Attack_Grid.h"
#include "Unit.h"
#include <vector>

class Game{
    public:
        Game();
        virtual void setUnits(); //virtuale pura da usare nel costruttore che rende classe astratta
        void clearSonar(); //per gestire il comando speciale AA AA


    protected:
        int n_turns;
        static const int n_Corazzate = 3;
        static const int n_Supporto = 3;
        static const int n_Sottomarino = 2;

        Attack_Grid player1_attack;
        Defense_Grid player2_attack;
        Attack_Grid player1_attack;
        Defense_Grid player2_attack;


        std::vector<Grid::Position> player1_units; //salva la posizione centrale delle unità
        std::vector<Grid::Position> player2_units; //la size di questi vettori rappresenta il numero di unita non affondate

};


#endif