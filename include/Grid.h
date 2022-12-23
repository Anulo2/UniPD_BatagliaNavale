#ifndef GRID_H
#define GRID_H

/*

    A
    B
    C
    D
    E
    F
    G
    H
    I
    L
    M
    N
        1  2  3  4  5  6  7  8  9 10 11 12
    
    griglia di attacco  == griglia di difesa
*/

class Grid{ 
    public:

        struct Position{
            int x; 
            int y; 

            Position();
            Position(int Y, int X);
        };

        /**Costruttori**/
        Grid();

        /**Getters**/
        //restituisce la griglia
        char* grid(); 

        /**Disegna la griglia**/
        void drawGrid();

        //valore della posizione xy
        char positionValue(const Position& obj);  

        /**Setters**/
        void setValue(Position& obj, char v);

        virtual bool isValidChar(const char& v)=0;


    private:
        static const int ROW_MAX = 12;
        static const int COL_MAX = 12;

        char grid_[COL_MAX][ROW_MAX]{};
        
};

#endif