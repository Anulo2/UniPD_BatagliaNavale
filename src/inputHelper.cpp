#include "inputHelper.h"

void inputHelper::writeLog(std::ostream &os, std::vector<std::string> log) {
    for (int i = 0; i < log.size(); i++)
        os << log[i] << "\n";
}

std::string inputHelper::logToString(std::vector<std::string> log) {
    std::string toString;
    for (int i = 0; i < log.size(); i++)
        toString += log[i] += "\n";

    return toString;
}

std::string inputHelper::addContentToLog(std::shared_ptr<Unit> obj) {

    std::string coordBow = obj->getBow().getY() + std::to_string(obj->getBow().getX());
    std::string coordStern = obj->getStern().getY() + std::to_string(obj->getStern().getX());
    return coordStern + " " + coordBow;
}

std::string inputHelper::addContentToLog(Position target, std::string actionUnit) {
    std::string pos{};
    std::string coordtarget = target.getY() + std::to_string(target.getX());
    pos += actionUnit + " " + coordtarget;
    return pos;
}

std::string inputHelper::getPlayerInput(std::istream &is) {
    std::string in{};
    std::getline(is, in, '\n');
    return in;
}

int inputHelper::stringTointeger(std::string str) {
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

std::vector<Position> inputHelper::inputString(std::string in){
    //throw std::out_of_range!
    std::string XY1 = in.substr(0, in.find(" "));
    //throw std::out_of_range!
    std::string XY2 = in.substr(in.find(" ") + 1, in.npos); 


    if (XY2.length() > 2)
        XY2 = XY2.substr(0, XY2.find(" "));

    char y1 = XY1[0];
    std::string strx1 = XY1.substr(
        1,
        XY1.length() - 1); // estrazione dei caratteri dall'inizio all'ultimo-1
    int x1 = inputHelper::stringTointeger(strx1);

    // estrazione dell'ultimo carattere
    char y2 = XY2[0];
    std::string strx2 = XY2.substr(
        1,
        XY2.length() - 1); // estrazione dei caratteri dall'inizio all'ultimo-1
    int x2 = inputHelper::stringTointeger(strx2);

    Position bow(x1, y1);
    Position stern(x2, y2);

    return std::vector<Position>{bow, stern};
}

std::shared_ptr<Battleship> inputHelper::inputBattleship(const std::string in) {

    std::vector<Position> iPositions{inputHelper::inputString(in)};

    std::shared_ptr<Battleship> iBattleship(new Battleship(iPositions.at(0), iPositions.at(1)));

    // std::cout << "\n" << iBattleship << "\n";

    return iBattleship;
}

std::shared_ptr<Support> inputHelper::inputSupport(const std::string in) {

    std::vector<Position> iPositions{inputHelper::inputString(in)};

    std::shared_ptr<Support> iSupport(new Support(iPositions.at(0), iPositions.at(1)));

    // std::cout << "\n" << iSupport << "\n";

    return iSupport;
}

std::shared_ptr<Submarine> inputHelper::inputSubmarine(const std::string in) {

    std::vector<Position> iPositions{inputHelper::inputString(in)};

    std::shared_ptr<Submarine> iSubmarine(new Submarine(iPositions.at(0), iPositions.at(1)));

    // std::cout << "\n" << iSubmarine << "\n";

    return iSubmarine;
}

std::shared_ptr<Unit> inputHelper::randomBattleship() {
    std::random_device rand;

    std::uniform_int_distribution<int> VerticalDistribution(0, 1);
    std::uniform_int_distribution<int> Xdistribution(3, 10);
    std::uniform_int_distribution<int> Ydistribution(1, 12);

    // 1 vertical, 0 horizontal
    int vert = VerticalDistribution(rand);
    if (vert == 0) {
        int x = Xdistribution(rand);
        int y = Ydistribution(rand);

        std::shared_ptr<Unit> battleShip(
            new Battleship(Position(x - 2, y), Position(x + 2, y)));

        return battleShip;
    } else {
        int x = Ydistribution(rand);
        int y = Xdistribution(rand);

        std::shared_ptr<Unit> buffer(
            new Battleship(Position(x, y - 2), Position(x, y + 2)));

        return buffer;
    }
}

std::shared_ptr<Unit> inputHelper::randomSupport() {
    std::random_device rand;

    std::uniform_int_distribution<int> VerticalDistribution(0, 1);
    std::uniform_int_distribution<int> Xdistribution(2, 10);
    std::uniform_int_distribution<int> Ydistribution(1, 12);

    // 1 vertical, 0 horizontal

    int vert = VerticalDistribution(rand);
    if (vert == 0) {
        int x = Xdistribution(rand);
        int y = Ydistribution(rand);

        std::shared_ptr<Unit> buffer(
            new Support(Position(x - 1, y), Position(x + 1, y)));

        return buffer;
    } else {
        int x = Ydistribution(rand);
        int y = Xdistribution(rand);

        std::shared_ptr<Unit> buffer(
            new Support(Position(x, y - 1), Position(x, y + 1)));

        return buffer;
    }
}

std::shared_ptr<Unit> inputHelper::randomSubmarine() {
    std::random_device rand;

    std::uniform_int_distribution<int> Xdistribution(1, 12);
    std::uniform_int_distribution<int> Ydistribution(1, 12);

    int x = Xdistribution(rand);
    int y = Ydistribution(rand);
    std::shared_ptr<Unit> buffer(new Submarine(Position(x, y), Position(x, y)));

    return buffer;
}

//Random action function.
//The action will be done by player1
std::string inputHelper::randomAction(Controller *player1, Controller *player2) {
    std::string log{};
    Position finalTarget;
    std::string finalActionUnit;

    std::random_device rand;

    std::uniform_int_distribution<int> randomUnitdistribuition(0, player1->getUnits().size() - 1);
    std::uniform_int_distribution<int> Xdistribution(1, 12);
    std::uniform_int_distribution<int> Ydistribution(1, 12);

    int ship = randomUnitdistribuition(rand);

    std::shared_ptr<Unit> actionUnit = player1->getUnits()[ship];
    finalActionUnit = actionUnit->getMiddle().getY() + std::to_string(actionUnit->getMiddle().getX());

    char type = actionUnit->getId();
    bool valid = false;

    std::cout << "######################################\n";
    std::cout << "########  ACTION COMPUTER FIELD ######\n";
    std::cout << "######################################\n";

    while (!valid) {
        
        valid = false;
        int xTarget = Xdistribution(rand);
        int yTarget = Ydistribution(rand);
        Position target(xTarget, yTarget);

        if (type == 'C') {
            std::vector<std::shared_ptr<Unit>> enemyUnit = {
                player2->getUnit(target)};

            std::vector<std::shared_ptr<Entity>> enemyEntities =
                actionUnit->action(target, enemyUnit);
            valid = true;

            player1->mergeEntities(enemyEntities);
            player2->removeDeadUnits();

        } else if (type == 'S') {
            if (actionUnit->isVertical()) {
                try {
                    std::shared_ptr<Unit> buffer(
                        new Support(Position(xTarget, yTarget - 1),
                                    Position(xTarget, yTarget + 1)));
                    if (player1->checkUnitPlacement(actionUnit, buffer)) {
                        valid = true;
                    }
                } catch (std::invalid_argument e) {
                }
            } else {
                try {
                    std::shared_ptr<Unit> buffer(
                        new Support(Position(xTarget - 1, yTarget),
                                    Position(xTarget + 1, yTarget)));
                    if (player1->checkUnitPlacement(actionUnit, buffer)) {
                        valid = true;
                    }
                } catch (std::invalid_argument e) {
                }
            }
            if (valid) {

                std::vector<std::shared_ptr<Unit>> bufferUnit =
                    player1->getUnitsInRange(target, 1);
                std::vector<std::shared_ptr<Entity>> enemyEntities =
                    actionUnit->action(target, bufferUnit);
                player1->mergeEntities(enemyEntities);
            }

        } else if (type == 'E') {
            std::shared_ptr<Unit> buffer(new Submarine(
                Position(xTarget, yTarget), Position(xTarget, yTarget)));
            if (player1->checkUnitPlacement(actionUnit, buffer)) {
                valid = true;
            }

            if (valid) {

                std::vector<std::shared_ptr<Unit>> bufferUnit =
                    player2->getUnitsInRange(target, 2);
                std::vector<std::shared_ptr<Entity>> enemyEntities =
                    actionUnit->action(target, bufferUnit);
                player1->mergeEntities(enemyEntities);
            }
        }

        finalTarget = target;
    }
    
    log = addContentToLog(finalTarget, finalActionUnit);

    std::cout<<"\n\t-> "<<log<<" ";
            
    return log;
}

std::string inputHelper::handlePlayerAction(Controller *player1, Controller *player2, std::string iLogStr) {

    std::string log;
    std::shared_ptr<Unit> actionUnit;

    bool valid = false;
    bool specialChar = false;

    std::cout << "######################################\n";
    std::cout << "########  ACTION PLAYER FIELD   ######\n";
    std::cout << "######################################\n";

    // TODO NON SONO SICURO FRATOMO TESTARE E AGGIUNGERE EVENTUALI CONTROLLI

    while (!actionUnit || !valid) {
        std::cout << "An action has this format: B10 G6\n"
                     "A special string can be used to display your defense and attack field: XX XX\n"
                     "The first coordinate rappresent the middle pos of the ship that will do the action\n"
                     "the second coordinate represents the target position of the action\n->  ";

        try {
            std::string action;
            std::vector<Position> result;

            if (iLogStr.length() == 0) {

                action = inputHelper::getPlayerInput(std::cin);
                
                if (action == "XX XX") {
                    std::cout << player1 << std::endl;
                    specialChar = true;

                } else {
                    result = inputHelper::inputString(action);
                    actionUnit = player1->getUnit(result[0]);
                    log = action;
                }

            } else {
                result = inputHelper::inputString(iLogStr);
                actionUnit = player1->getUnit(result[0]);
                log = iLogStr;    
            }

            
            if (actionUnit && specialChar) {
                
                Position target = result[1];

                char type = actionUnit->getId();

                if (type == 'C') {

                    std::vector<std::shared_ptr<Unit>> enemyUnit = {
                        player2->getUnit(target)};

                    std::vector<std::shared_ptr<Entity>> enemyEntities =
                        actionUnit->action(target, enemyUnit);
                    valid = true;
                    specialChar = true;

                    player1->mergeEntities(enemyEntities);
                    player2->removeDeadUnits();

                } else if (type == 'S') {
                    if (actionUnit->isVertical()) {
                        try {
                            std::shared_ptr<Unit> buffer(new Support(
                                Position(target.getX(), target.getIntY() - 1),
                                Position(target.getX(), target.getIntY() + 1)));
                            if (player1->checkUnitPlacement(actionUnit, buffer)) {
                                valid = true;
                                specialChar = true;
                            }
                        } catch (std::invalid_argument e) {
                        }
                    } else {
                        try {
                            std::shared_ptr<Unit> buffer(new Support(
                                Position(target.getX() - 1, target.getIntY()),
                                Position(target.getX() + 1, target.getIntY())));
                            if (player1->checkUnitPlacement(actionUnit, buffer)) {
                                valid = true;
                                specialChar = true;
                            }
                        } catch (std::invalid_argument e) {
                        }
                    }
                    if (valid) {
                        std::vector<std::shared_ptr<Unit>> bufferUnit =
                            player1->getUnitsInRange(target, 1);
                        std::vector<std::shared_ptr<Entity>> enemyEntities =
                            actionUnit->action(target, bufferUnit);
                        player1->mergeEntities(enemyEntities);
                    }
                } else if (type == 'E') {
                    std::shared_ptr<Unit> buffer(new Submarine(
                        Position(target.getX(), target.getIntY()),
                        Position(target.getX(), target.getIntY())));
                    if (player1->checkUnitPlacement(actionUnit, buffer)) {
                        valid = true;
                        specialChar = true;
                    }

                    if (valid) {
                        std::vector<std::shared_ptr<Unit>> bufferUnit =
                            player2->getUnitsInRange(target, 2);
                        std::vector<std::shared_ptr<Entity>> enemyEntities =
                            actionUnit->action(target, bufferUnit);
                        player1->mergeEntities(enemyEntities);
                    }
                }
            }

        } catch (std::invalid_argument e) {
        }

    }
    
    return log;
}
