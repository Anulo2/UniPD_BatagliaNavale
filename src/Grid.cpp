#include<iostream>
#include "Grid.h"

//Struct Position
Grid::Position::Position(){}
Grid::Position::Position(int X, int Y, char val): x{X}, y{y}, value{val} {}

char Grid::positionValue(Position& obj){
    return obj.value;
}

Grid::Grid(){
    for(int i = 0; i < ROW_MAX; i ++){
        for(int j = 0; j < ROW_MAX; j++){
            grid_[i][j] = ' ';
        }
    }
}

//restituisce la griglia
char* Grid::grid(){
    return &grid_[0][0];
}

void Grid::drawGrid(){

    char rawID[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};
    for(int i = 0; i <= ROW_MAX; i++){
        
        if(i < ROW_MAX){
             std::cout<<rawID[i];

            for(int j = 0; j < COL_MAX; j++){
                std::cout<<"\t"<<grid_[i][j];
            }
            std::cout<<"\n\n";
        }
        
        else {
            std::cout<<"\t";
            for(int i = 1; i <= COL_MAX; i++) std::cout<<i<<"\t";
        }        
    }

}