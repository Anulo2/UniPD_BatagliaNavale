#include<iostream> 
#include "Grid.h"
#include "Attack_Grid.h"
#include "Defense_Grid.h"
using namespace std;

int main(int argc, char* argv[]){
    Defense_Grid uno;
    uno.drawGrid();
    char* a = uno.grid();

    return 0;
}