#include "PlayerVSComputer.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>  //librerie per generare posizioni casuali dove piazzare le navi
#include <iostream>
#include <random>

PlayerVSComputer::PlayerVSComputer() {
    std::srand(std::time(nullptr));
    bool placed;
    // int x, y, vert;
    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player1
        placed = false;
        while (!placed) {
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale
            if (vert == 0) {
                int x = rand() % 10 + 1;
                int y = rand() % 12 + 1;
                if (player1.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))) {
                    player1.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                int x = rand() % 12 + 1;
                int y = rand() % 10 + 1;
                if (player1.checkUnitPlacement(new Battleship(Position(x, y - 2), Position(x, y + 2)))) {
                    player1.addUnit(new Battleship(Position(x, y - 2), Position(x, y + 2)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Vert\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // piazzo le corazzate del player2 in modo random come pcvspc
        placed = false;
        while (!placed) {
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 10 + 1;
                int y = rand() % 12 + 1;
                if (player2.checkUnitPlacement(new Battleship(Position(x - 2, y), Position(x + 2, y)))) {
                    player2.addUnit(new Battleship(Position(x - 2, y), Position(x + 2, y)));
                    placed = true;
                }

            } else {
                int x = rand() % 12 + 1;
                int y = rand() % 10 + 1;
                if (player2.checkUnitPlacement(new Battleship(Position(x, y - 2), Position(x, y + 2)))) {
                    player2.addUnit(new Battleship(Position(x, y - 2), Position(x, y + 2)));
                    placed = true;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player1
        placed = false;
        while (!placed) {
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 11 + 1;
                int y = rand() % 12 + 1;
                if (player1.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                    player1.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Horiz\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }

            } else {
                int x = rand() % 12 + 1;
                int y = rand() % 11 + 1;
                if (player1.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                    player1.addUnit(new Support(Position(x, y - 1), Position(x, y + 1)));
                    placed = true;
                    // std::cout << Position(x, y) << ", Vert\n";
                    // printDefense(player1.getUnits());
                } else {
                    // std::cout << "Failed to place horizontal Battleship of Player1 at pos: " << Position(x, y) << "\n";
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {  // piazzo i supporti del player2 random come pcvspc
        placed = false;
        while (!placed) {
            int vert = rand() % 2;  // 1 verticale, 0 orizzontale

            if (vert == 0) {
                int x = rand() % 11 + 1;
                int y = rand() % 12 + 1;
                if (player2.checkUnitPlacement(new Support(Position(x - 1, y), Position(x + 1, y)))) {
                    player2.addUnit(new Support(Position(x - 1, y), Position(x + 1, y)));
                    placed = true;
                }

            } else {
                int x = rand() % 12 + 1;
                int y = rand() % 11 + 1;
                if (player2.checkUnitPlacement(new Support(Position(x, y - 1), Position(x, y + 1)))) {
                    player2.addUnit(new Support(Position(x, y - 1), Position(x, y + 1)));
                    placed = true;
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) {  // piazzo i sttomarini del player1
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            if (!player1.isUnit(Position(x, y))) {
                player1.addUnit(new Submarine(Position(x, y), Position(x, y)));
                placed = true;
            }
        }
    }
    for (int i = 0; i < 2; i++) {  // piazzo i sottomarini del player 2 random come pcvspc
        placed = false;
        while (!placed) {
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            if (!player2.isUnit(Position(x, y))) {
                player2.addUnit(new Submarine(Position(x, y), Position(x, y)));
                placed = true;
            }
        }
    }
}

Controller *PlayerVSComputer::getPlayer1() {
    return &player1;
}

Controller *PlayerVSComputer::getPlayer2() {
    return &player2;
}

Battleship *inputBattleship(void) {
    bool done = false;
    while (!done) {
        std::string inp;
        std::cout << "#inserire coordinate rispettivamente per poppa e prua della corazzata nel formato XY XY#\n";
        std::cin >> inp;

        // TODO: input string manipulation
        int x_bow = 0;
        int y_bow = 0;

        Position bow(x_bow, y_bow);  // TODO:CONTROLLI (da fare su costruttore position?)

        int x_stern = 0;
        int y_stern = 0;

        Position stern(x_stern, y_stern);  // TODO:CONTROLLI (da fare su costruttore position?)

        try {
            static Battleship iBattleship(bow, stern);
            return &iBattleship;
        } catch (...) {
            ;
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
}

Support *inputSupport() {
    bool done = false;
    while (!done) {
        std::string inp;
        std::cout << "#inserire coordinate rispettivamente per poppa e prua della nave supporto nel formato XY XY#\n";
        std::cin >> inp;

        // TODO: input string manipulation
        int x_bow = 0;
        int y_bow = 0;

        Position bow(x_bow, y_bow);  // TODO:CONTROLLI (da fare su costruttore position?)

        int x_stern = 0;
        int y_stern = 0;

        Position stern(x_stern, y_stern);  // TODO:CONTROLLI (da fare su costruttore position?)

        try {
            static Support iSupport(bow, stern);
            return &iSupport;
        } catch (...) {
            ;
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
}

Submarine *inputSubmarine() {
    bool done = false;
    while (!done) {
        std::string inp;
        std::cout << "#inserire coordinata per il sottomarino nel formato XY #\n";
        std::cin >> inp;

        // TODO: input string manipulation
        int x = 0;
        int y = 0;

        Position pos(x, y);  // TODO:CONTROLLI (da fare su costruttore position?)

        try {
            static Submarine iSubmarine(pos, pos);
            return &iSubmarine;
        } catch (...) {
            ;
        };  // TODO:CHECK idea: non deve fare nulla se vengono lanciate eccezioni perche il ciclo va avanti e riprova (viene interrotto dal return)
    }
}