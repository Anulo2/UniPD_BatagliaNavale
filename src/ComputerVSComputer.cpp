#include "ComputerVSComputer.h"

ComputerVSComputer::ComputerVSComputer() {
    std::random_device rand;
    std::uniform_int_distribution<int> ranomPlayer(0, 1);
    // true  = player 1
    selectPlayer = ranomPlayer(rand);
    int placing = 0;

    bool placed;
    bool placedUnitP1 = false;
    bool placedUnitP2 = false;
    while (!placed) {
        if (selectPlayer == 0) {
            // Placing battleships of player1
            for (int i = 0; i < 3; i++) {
                placedUnitP1 = false;
                while (!placedUnitP1) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomBattleship());
                        if (player1.checkUnitPlacement(buffer, buffer)) {
                            player1.addUnit(buffer);
                            placedUnitP1 = true;

                            log.push_back(Helper::addContentToLog(buffer));
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

            // Placing support of player1
            for (int i = 0; i < 3; i++) {
                placedUnitP1 = false;
                while (!placedUnitP1) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomSupport());
                        if (player1.checkUnitPlacement(buffer, buffer)) {
                            player1.addUnit(buffer);
                            placedUnitP1 = true;

                            log.push_back(Helper::addContentToLog(buffer));
                        } else {
                            // std::cout << "Failed to place vertical Battleship of Player2 at pos: " << Position(x, y) << "\n";
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "\nInvalid Pos for support p1" << std::endl;
                    }
                }

                std::cout << "Placed Support Player1!\n";
            }

            // Placing submarines of player1
            for (int i = 0; i < 2; i++) {
                placedUnitP1 = false;
                while (!placedUnitP1) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomSubmarine());
                        if (player1.checkUnitPlacement(buffer, buffer)) {
                            player1.addUnit(buffer);
                            placedUnitP1 = true;

                            log.push_back(Helper::addContentToLog(buffer));
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
        }
        if (selectPlayer == 1) {
            // Placing battleships of player2
            for (int i = 0; i < 3; i++) {
                placedUnitP2 = false;
                while (!placedUnitP2) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomBattleship());
                        if (player2.checkUnitPlacement(buffer, buffer)) {
                            player2.addUnit(buffer);
                            placedUnitP2 = true;

                            log.push_back(Helper::addContentToLog(buffer));
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

            // Placing support of player2
            for (int i = 0; i < 3; i++) {
                placedUnitP1 = false;
                while (!placedUnitP2) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomSupport());
                        if (player2.checkUnitPlacement(buffer, buffer)) {
                            player2.addUnit(buffer);
                            placedUnitP2 = true;

                            log.push_back(Helper::addContentToLog(buffer));
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
            // Placing submarines of player2
            for (int i = 0; i < 2; i++) {
                placedUnitP2 = false;
                while (!placedUnitP2) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomSubmarine());
                        if (player2.checkUnitPlacement(buffer, buffer)) {
                            player2.addUnit(buffer);
                            placedUnitP2 = true;

                            log.push_back(Helper::addContentToLog(buffer));
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

        if (selectPlayer == 0) {
            selectPlayer++;
        } else {
            selectPlayer--;
        }
        if (placedUnitP1 && placedUnitP2) placed = true;
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
    std::vector<std::string> buffer = log;
    log.clear();
    return buffer;
}

int ComputerVSComputer::getStartingPlayer() {
    return selectPlayer;
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