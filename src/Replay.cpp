#include "Replay.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/

Replay::Replay(std::vector<std::string> in) {
    bool placed;
    int iterator = 0;
    static const int nTotalUnitsInGame = 16;

    while (iterator < nTotalUnitsInGame) {
        // Placing battleships of player1
        for (int i = 0; i < 3; i++) {
            placed = false;
            while (!placed) {
                std::shared_ptr<Battleship> buffer = Helper::inputBattleship(in[iterator]);
                std::shared_ptr<Unit> battleShip(buffer);

                if (player1.checkUnitPlacement(buffer, battleShip)) {
                    player1.addUnit(battleShip);
                    placed = true;
                    // player1.printDefense(std::cout);
                } else {
                    std::cout << "input non valido, c'è gia una nave\n";
                }
            }
            log.push_back(in[iterator]);
            iterator++;
        }

        // Placing battleships of player2
        for (int i = 0; i < 3; i++) {
            placed = false;
            while (!placed) {
                std::shared_ptr<Battleship> buffer = Helper::inputBattleship(in[iterator]);
                std::shared_ptr<Unit> battleShip(buffer);

                if (player2.checkUnitPlacement(buffer, battleShip)) {
                    player2.addUnit(battleShip);
                    placed = true;
                    // player2.printDefense(std::cout);
                } else {
                    std::cout << "input non valido, c'è gia una nave\n";
                }
            }
            log.push_back(in[iterator]);
            iterator++;
        }

        // Placing supports of player1
        for (int i = 0; i < 3; i++) {
            placed = false;
            while (!placed) {
                std::shared_ptr<Support> buffer = Helper::inputSupport(in[iterator]);
                std::shared_ptr<Unit> support(buffer);

                if (player1.checkUnitPlacement(buffer, support)) {
                    player1.addUnit(support);
                    placed = true;
                    // player1.printDefense(std::cout);
                } else {
                    std::cout << "input non valido, c'è gia una nave\n";
                }
            }
            log.push_back(in[iterator]);
            iterator++;
        }

        // Placing supports of player2
        for (int i = 0; i < 3; i++) {
            placed = false;
            while (!placed) {
                std::shared_ptr<Support> buffer = Helper::inputSupport(in[iterator]);
                std::shared_ptr<Unit> support(buffer);

                if (player2.checkUnitPlacement(buffer, support)) {
                    player2.addUnit(support);
                    placed = true;
                    // player2.printDefense(std::cout);
                } else {
                    std::cout << "input non valido, c'è gia una nave\n";
                }
            }
            log.push_back(in[iterator]);
            iterator++;
        }

        // Placing submarines of player1
        for (int i = 0; i < 2; i++) {
            placed = false;
            while (!placed) {
                std::shared_ptr<Submarine> buffer = Helper::inputSubmarine(in[iterator]);
                std::shared_ptr<Unit> submarine(buffer);

                if (player1.checkUnitPlacement(buffer, submarine)) {
                    player1.addUnit(submarine);
                    placed = true;
                    // player1.printDefense(std::cout);
                } else {
                    std::cout << "input non valido, c'è gia una nave\n";
                }
            }
            log.push_back(in[iterator]);
            iterator++;
        }

        // Placing submarines of player1
        for (int i = 0; i < 2; i++) {
            placed = false;
            while (!placed) {
                std::shared_ptr<Submarine> buffer = Helper::inputSubmarine(in[iterator]);
                std::shared_ptr<Unit> submarine(buffer);

                if (player2.checkUnitPlacement(buffer, submarine)) {
                    player2.addUnit(submarine);
                    placed = true;
                    // player2.printDefense(std::cout);
                } else {
                    std::cout << "input non valido, c'è gia una nave\n";
                }
            }
            log.push_back(in[iterator]);
            iterator++;
        }

        // end placing unit
    }  // end of while
}

/*********************************************************
 *                  GETTER FUNCTIONS                     *
 **********************************************************/

Controller *Replay::getPlayer1() {
    return &player1;
}

Controller *Replay::getPlayer2() {
    return &player2;
}

std::vector<std::string> Replay::getLog() {
    return log;
}

/*********************************************************
 *                  SETTER FUNCTIONS                      *
 **********************************************************/

void Replay::addStringToLog(std::string iLog) {
    log.push_back(iLog);
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

std::ostream &operator<<(std::ostream &os, Replay &a) {
    // Helper::writeLog(os, a.getLog());
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream &operator<<(std::ostream &os, Replay *a) {
    os << *a;
    return os;
}
