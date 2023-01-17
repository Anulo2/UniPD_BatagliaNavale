#include "ComputerVSComputer.h"

ComputerVSComputer::ComputerVSComputer() {
    bool placed;
    // Placing battleships of player1
    for (int i = 0; i < 3; i++) {
        placed = false;
        while (!placed) {
            try {
                std::shared_ptr<Unit> buffer(inputHelper::randomBattleship());
                if (player1.checkUnitPlacement(buffer, buffer)) {
                    player1.addUnit(buffer);
                    placed = true;

                    log.push_back(inputHelper::addContentToLog(buffer));
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch (std::invalid_argument e) {
                std::cout << "\nInvalid Pos for battleship p1\n"
                          << std::endl;
                std::cout << e.what() << "\n";
            }
        }

        std::cout << "Placed Battleship Player1!\n";
    }

    // Placing battleships of player2
    for (int i = 0; i < 3; i++) {
        placed = false;
        while (!placed) {
            try {
                std::shared_ptr<Unit> buffer(inputHelper::randomBattleship());
                if (player2.checkUnitPlacement(buffer, buffer)) {
                    player2.addUnit(buffer);
                    placed = true;

                    log.push_back(inputHelper::addContentToLog(buffer));
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch (std::invalid_argument e) {
                std::cout << "\nInvalid Pos for battleship p1\n"
                          << std::endl;
                std::cout << e.what() << "\n";
            }
        }

        std::cout << "Placed Battleship Player2!\n";
    }

    // Placing support of player1
    for (int i = 0; i < 3; i++) {
        placed = false;
        while (!placed) {
            try {
                std::shared_ptr<Unit> buffer(inputHelper::randomSupport());
                if (player1.checkUnitPlacement(buffer, buffer)) {
                    player1.addUnit(buffer);
                    placed = true;

                    log.push_back(inputHelper::addContentToLog(buffer));
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch (std::invalid_argument) {
                std::cout << "\nInvalid Pos for support p1" << std::endl;
            }
        }

        std::cout << "Placed Support Player1!\n";
    }

    // Placing support of player2
    for (int i = 0; i < 3; i++) {
        placed = false;
        while (!placed) {
            try {
                std::shared_ptr<Unit> buffer(inputHelper::randomSupport());
                if (player2.checkUnitPlacement(buffer, buffer)) {
                    player2.addUnit(buffer);
                    placed = true;

                    log.push_back(inputHelper::addContentToLog(buffer));
                } else {
                    // std::cout << "Failed to place vertical Battleship of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch (std::invalid_argument e) {
                std::cout << "\nInvalid Pos for Support p2 \n"
                          << std::endl;
                std::cout << e.what() << "\n";
            }
        }

        std::cout << "Placed Support Player2!\n";
    }

    // Placing submarines of player1
    for (int i = 0; i < 2; i++) {
        placed = false;
        while (!placed) {
            try {
                std::shared_ptr<Unit> buffer(inputHelper::randomSubmarine());
                if (player1.checkUnitPlacement(buffer, buffer)) {
                    player1.addUnit(buffer);
                    placed = true;

                    log.push_back(inputHelper::addContentToLog(buffer));
                } else {
                    // std::cout << "Failed to place vertical submarine of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch (std::invalid_argument e) {
                std::cout << "\nInvalid Pos for submarine p1 \n"
                          << std::endl;
                std::cout << e.what() << "\n";
            }
        }

        std::cout << "Placed submarine Player1!\n";
    }

    // Placing submarines of player2
    for (int i = 0; i < 2; i++) {
        placed = false;
        while (!placed) {
            try {
                std::shared_ptr<Unit> buffer(inputHelper::randomSubmarine());
                if (player2.checkUnitPlacement(buffer, buffer)) {
                    player2.addUnit(buffer);
                    placed = true;

                    log.push_back(inputHelper::addContentToLog(buffer));
                } else {
                    // std::cout << "Failed to place vertical submarine of Player2 at pos: " << Position(x, y) << "\n";
                }
            } catch (std::invalid_argument e) {
                std::cout << "\nInvalid Pos for submarine p2 \n"
                          << std::endl;
                std::cout << e.what() << "\n";
            }
        }

        std::cout << "Placed submarine Player2!\n";
    }
}

/*********************************************************
 *                  GETTER FUNCTIONS                     *
 **********************************************************/

Controller *ComputerVSComputer::getPlayer1() {
    return &player1;
}

Controller *ComputerVSComputer::getPlayer2() {
    return &player2;
}

std::vector<std::string> ComputerVSComputer::getLog() {
    return log;
}

/*********************************************************
 *                  SETTER FUNCTIONS                     *
 **********************************************************/

void ComputerVSComputer::addToLog(std::shared_ptr<Entity> obj) {
    std::string coordBow = obj->getPos().getY() + std::to_string(obj->getPos().getX());
    std::string coordStern = obj->getPos().getY() + std::to_string(obj->getPos().getX());
    log.push_back(coordStern + " " + coordBow);
}

void ComputerVSComputer::addStringToLog(std::string iLog) {
    log.push_back(iLog);
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

std::ostream &operator<<(std::ostream &os, ComputerVSComputer &a) {
    // inputHelper::writeLog(os, a.getLog());
    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream &operator<<(std::ostream &os, ComputerVSComputer *a) {
    os << *a;
    return os;
}