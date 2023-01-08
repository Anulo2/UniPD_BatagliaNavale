#include "ComputerVSComputer.h"

#include <cstdlib>
#include <ctime>  //librerie per generare posizioni casuali dove piazzare le navi

ComputerVSComputer::ComputerVSComputer() {
    srand(time(NULL));  // seme della randomicità
    bool placed;

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {
                // metodo per vedere se non ci sono unità che occupano sopra o sotto di due caselle rispetto (x,y) da implementare in controller
                Battleship buffer(Position(x - 2, y), Position(x + 2, y));
                player1.addUnit(&buffer);
                placed = true;
            } else {
                // metodo per vedere se non ci sono unità che occupano a dx o sx di due caselle rispetto (x,y) da implementare in controller
                Battleship buffer(Position(x, y - 2), Position(x, y + 2));
                player1.addUnit(&buffer);
                placed = true;
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {
                // metodo per vedere se non ci sono unità che occupano sopra o sotto di due caselle rispetto (x,y) da implementare in controller
                Battleship buffer(Position(x - 2, y), Position(x + 2, y));
                player2.addUnit(&buffer);
                placed = true;
            } else {
                // metodo per vedere se non ci sono unità che occupano a dx o sx di due caselle rispetto (x,y) da implementare in controller
                Battleship buffer(Position(x, y - 2), Position(x, y + 2));
                player2.addUnit(&buffer);
                placed = true;
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {
                // metodo per vedere se non ci sono unità che occupano sopra o sotto di 1 casella rispetto (x,y) da implementare in controller
                Support buffer(Position(x - 1, y), Position(x + 1, y));
                player1.addUnit(&buffer);
                placed = true;
            } else {
                // metodo per vedere se non ci sono unità che occupano a dx o sx di una casella rispetto (x,y) da implementare in controller
                Support buffer(Position(x, y - 1), Position(x, y + 1));
                player1.addUnit(&buffer);
                placed = true;
            }
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i supporti del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            int vert = rand() % 2;  // 0 verticale, 1 orizzontale

            if (vert == 0) {
                // metodo per vedere se non ci sono unità che occupano sopra o sotto di 1 casella rispetto (x,y) da implementare in controller
                Support buffer(Position(x - 1, y), Position(x + 1, y));
                player2.addUnit(&buffer);
                placed = true;
            } else {
                // metodo per vedere se non ci sono unità che occupano a dx o sx di una casella rispetto (x,y) da implementare in controller
                Support buffer(Position(x, y - 1), Position(x, y + 1));
                player2.addUnit(&buffer);
                placed = true;
            }
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sottomarini del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;

            // metodo per vedere se non ci sono unità che occupano la casella (x,y) da implementare in controller
            Support buffer(Position(x - 1, y), Position(x + 1, y));
            player1.addUnit(&buffer);
            placed = true;
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sottomarini del player2
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;

            // metodo per vedere se non ci sono unità che occupano la casella (x,y) da implementare in controller
            Support buffer(Position(x - 1, y), Position(x + 1, y));
            player2.addUnit(&buffer);
            placed = true;
        }
    }
}
