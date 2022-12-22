#include<iostream> 
#include "Grid.h"
using namespace std;

int main(int argc, char* argv[]){
    Grid uno;
    uno.drawGrid();
    char* a = uno.grid();

    return 0;
}