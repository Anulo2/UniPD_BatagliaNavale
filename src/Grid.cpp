#include<iostream>
#include "Grid.h"

//Struct Position
Grid::Position::Position(){}
Grid::Position::Position(int X, int Y): x{X}, y{Y} {}


Grid::Grid(){
    for(int i = 0; i < COL_MAX; i ++){
        for(int j = 0; j < ROW_MAX; j++){
            grid_[i][j] = ' ';
        }
    }
}

char Grid::positionValue(const Position& obj){
    return grid_[obj.y][obj.x];
}

void Grid::setValue(Position& obj, char v){
    grid_[obj.y][obj.x]=v;
}


//restituisce la griglia
char* Grid::grid(){
    return &grid_[0][0];
}

void Grid::drawGrid(){

    char rowID[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};
    for(int i = 0; i <= ROW_MAX; i++){
        
        if(i < ROW_MAX){
             std::cout<<rowID[i];

            for(int j = 0; j < COL_MAX; j++){
                std::cout<<"\t"<<grid_[i][j];
            }
            std::cout<<"\n\n";
        }
        
        else {
            std::cout<<"\t";
            for(int i = 1; i <= ROW_MAX; i++) std::cout<<i<<"\t";
        }     
        std::cout<<"\n";   
    }

}