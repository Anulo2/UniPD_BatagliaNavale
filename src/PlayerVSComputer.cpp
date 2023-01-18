#include "PlayerVSComputer.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/

PlayerVSComputer::PlayerVSComputer() {
    std::random_device rand;
    std::uniform_int_distribution<int> ranomPlayer(0, 1);
    selectPlayer = ranomPlayer(rand);
    int placing = 0;
    bool placed;
    bool placedUnitP1 = false;
    bool placedUnitP2 = false;

    // int x, y, vert;

    // Placing battleships of player1
    while (!placed) {
        if (selectPlayer == 0) {
            for (int i = 0; i < 3; i++) {
                placedUnitP1 = false;
                while (!placedUnitP1) {
                    std::cout << "\nPlace battleship n: " << i + 1 << "\n";
                    try {
                        std::shared_ptr<Battleship> buffer = Helper::inputBattleship(Helper::getPlayerInput(std::cin));
                        std::shared_ptr<Unit> battleShip(buffer);

                        if (player1.checkUnitPlacement(battleShip, battleShip)) {
                            player1.addUnit(battleShip);
                            placedUnitP1 = true;

                            log.push_back(Helper::addContentToLog(buffer));

                        } else {
                            std::cout << "Invalid input, There is already a ship\n";
                        }

                    } catch (std::invalid_argument e) {
                        std::cout << "\n"
                                  << e.what() << std::endl;
                    } catch (std::out_of_range e) {
                        std::cout << "\n"
                                  << "Invalid string input" << std::endl;
                        std::cout << "\n"
                                  << "A valid input string has this format: A5 B5" << std::endl;
                    }
                }
                std::cout << "Battleship player1 n." << i + 1 << " placed!\n";
                // player1.printDefense(std::cout);
            }

            // Placing supports of player1
            for (int i = 0; i < 3; i++) {
                placedUnitP1 = false;
                while (!placedUnitP1) {
                    std::cout << "\nPlace support n: " << i + 1 << "\n";

                    try {
                        std::shared_ptr<Support> buffer = Helper::inputSupport(Helper::getPlayerInput(std::cin));
                        std::shared_ptr<Unit> support(buffer);

                        if (player1.checkUnitPlacement(support, support)) {
                            player1.addUnit(support);
                            placedUnitP1 = true;

                            log.push_back(Helper::addContentToLog(buffer));

                        } else {
                            std::cout << "Invalid input, There is already a ship\n";
                        }

                    } catch (std::invalid_argument e) {
                        std::cout << "\n"
                                  << e.what() << std::endl;
                    } catch (std::out_of_range e) {
                        std::cout << "\n"
                                  << "Invalid string input" << std::endl;
                        std::cout << "\n"
                                  << "A valid input string has this format: A5 B5" << std::endl;
                    }
                }
                std::cout << "Support player1 n." << i + 1 << " placed!\n";
                // player1.printDefense(std::cout);
            }

            // Placing submarines of player1
            for (int i = 0; i < 2; i++) {
                placedUnitP1 = false;
                while (!placedUnitP1) {
                    std::cout << "\nPlace submarine n: " << i + 1 << "\n";
                    try {
                        std::shared_ptr<Submarine> buffer = Helper::inputSubmarine(Helper::getPlayerInput(std::cin));
                        std::shared_ptr<Unit> submarine(buffer);
                        if (player1.checkUnitPlacement(submarine, submarine)) {
                            player1.addUnit(submarine);
                            placedUnitP1 = true;

                            log.push_back(Helper::addContentToLog(buffer));
                            // player1.printDefense(std::cout);
                            // player1.printAttack(std::cout);
                        } else {
                            std::cout << "Invalid input, There is already a ship\n";
                        }
                    } catch (std::invalid_argument e) {
                        std::cout << "\n"
                                  << e.what() << std::endl;
                    } catch (std::out_of_range e) {
                        std::cout << "\n"
                                  << "Invalid string input" << std::endl;
                        std::cout << "\n"
                                  << "A valid input string has this format: A5 B5" << std::endl;
                    }
                }
                std::cout << "Submarine player1 n." << i + 1 << " placed!\n";
                // player1.printDefense(std::cout);
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
                        std::cout << "\nInvalid Pos for battleship p2 \n"
                                  << std::endl;
                        std::cout << e.what() << "\n";
                    }
                }

                std::cout << "Battleship player2 n." << i + 1 << " placed!\n";
                // player2.printDefense(std::cout);
            }
            // Placing supports of player2
            for (int i = 0; i < 3; i++) {
                placedUnitP2 = false;
                while (!placedUnitP2) {
                    try {
                        std::shared_ptr<Unit> buffer(Helper::randomSupport());
                        if (player2.checkUnitPlacement(buffer, buffer)) {
                            player2.addUnit(buffer);
                            placedUnitP2 = true;

                            log.push_back(Helper::addContentToLog(buffer));
                        } else {
                            // std::cout << "Failed to place vertical support of Player2 at pos: " << Position(x, y) << "\n";
                        }
                    } catch (std::invalid_argument e) {
                        std::cout << "\n"
                                  << e.what() << std::endl;
                    }
                }

                std::cout << "Support player2 n." << i + 1 << " placed!\n";
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
                        std::cout << "\n"
                                  << e.what() << std::endl;
                    }
                }

                std::cout << "Submarine player2 n." << i + 1 << " placed!\n";
                // player2.printDefense(std::cout);
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

Controller* PlayerVSComputer::getPlayer1() {
    return &player1;
}

Controller* PlayerVSComputer::getPlayer2() {
    return &player2;
}

std::vector<std::string> PlayerVSComputer::getLog() {
    std::vector<std::string> buffer = log;
    log.clear();
    return buffer;
}

/*********************************************************
 *                  SETTER FUNCTIONS                     *
 **********************************************************/

void PlayerVSComputer::addToLog(std::shared_ptr<Unit> obj) {
    std::string coordBow = obj->getBow().getY() + std::to_string(obj->getBow().getX());
    std::string coordStern = obj->getStern().getY() + std::to_string(obj->getStern().getX());
    log.push_back(coordStern + " " + coordBow);
}

void PlayerVSComputer::addStringToLog(std::string iLog) {
    log.push_back(iLog);
}

int PlayerVSComputer::getStartingPlayer() {
    return selectPlayer;
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

std::ostream& operator<<(std::ostream& os, PlayerVSComputer& a) {
    // Helper::writeLog(os,a.getLog());

    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream& operator<<(std::ostream& os, PlayerVSComputer* a) {
    os << *a;
    return os;
}
