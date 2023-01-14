#include "Controller.h"

Controller::Controller() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            enemyEntitiesMatrix[i][j] = nullptr;
        }
    }
}

bool Controller::isUnit(Position iPos) {
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->containsPos(iPos)) {
            return true;
        }
    }
    return false;
}                                
void Controller::removeDeadUnits() {
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->getArmor() == 0) {
            units.erase(units.begin() + i);
            return;
        }
    }
}
std::vector<std::shared_ptr<Unit>> Controller::getUnits() {
    return units;
}

std::shared_ptr<Unit> Controller::getUnit(Position iPos) {
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->containsPos(iPos)) {
            return units[i];
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Unit>> Controller::getUnitsInRange(Position iPos, int range) {
    std::vector<std::shared_ptr<Unit>> unitsInRange;

    Position a(iPos.getX() - range, iPos.getIntY() - range);
    Position b(iPos.getX() + range, iPos.getIntY() + range);

    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).getBow().isInside(a, b) || (*units[i]).getStern().isInside(a, b) || (*units[i]).getMiddle().isInside(a, b)) {  // DUBBIO SU VERIFICA: se range = 1 e nave è corazzata può succedere che ne prua ne poppa sono dentro ma qualche altra casella della nave si
            unitsInRange.push_back(units[i]);
        }
    }

    return unitsInRange;
}

bool Controller::checkUnitPlacement(std::shared_ptr<Unit> iUnit) {
    Position a(1, 1);
    Position b(12, 12);
    if (iUnit->getBow().isInside(a, b) && iUnit->getStern().isInside(a, b)) {
        // std::cout << iUnit->getBow() << ", " << iUnit->getStern() <<"\n";
        std::vector<Position> buffer = iUnit->getUnitPositions();
        for (int i = 0; i < units.size(); i++) {
            for (int j = 0; j < buffer.size(); j++) {
                if (units[i]->containsPos(buffer[j])) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

void Controller::addUnit(std::shared_ptr<Unit> iUnit) {
    units.push_back(iUnit);
}

Controller::~Controller() {
}

void Controller::mergeEntities(std::vector<std::shared_ptr<Entity>> iEnemyEntities) {
    for (int i = 0; i < iEnemyEntities.size(); i++) {
        if (enemyEntitiesMatrix[iEnemyEntities[i]->getPos().getIntY() - 1][iEnemyEntities[i]->getPos().getX() - 1] != nullptr) {
            // Entity* bufferEntity = enemyEntitiesMatrix[buffer.getIntY() - 1][buffer.getX() - 1];
            //  if(bufferEntity->getId()!= 'X'){
            // bufferEntity->setId(iEnemyEntities[i]->getId());
            enemyEntitiesMatrix[iEnemyEntities[i]->getPos().getIntY() - 1][iEnemyEntities[i]->getPos().getX() - 1]->setId(iEnemyEntities[i]->getId());
            //}
        } else {
            std::shared_ptr<Entity> sharedPtr(iEnemyEntities[i]);
            enemyEntities.push_back(sharedPtr);
            enemyEntitiesMatrix[sharedPtr->getPos().getIntY() - 1][sharedPtr->getPos().getX() - 1] = sharedPtr;
        }
    }
}

char columns[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void Controller::printDefense(std::ostream& os) {  // Forse si può evitare il dopddio n^2 e farlo solo una volta, per ora va bene così
    char output[13][13];
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (j == 0) {
                output[i][j] = rows[i];
            } else {
                output[i][j] = '#';
            }
        }
    }

    std::copy(columns, columns + 13, output[12]);

    for (int i = 0; i < units.size(); i++) {
        std::vector<bool> status = units[i]->getStatus();
        //std::cout << units[i] << ", " << units[i]->getStern() << ", " << units[i]->getBow() << "\n";
        int dim = units[i]->getDimension();
        char id = units[i]->getId();
        if ((*units[i]).isVertical()) {
            for (int j = 0; j < dim; j++) {
                output[units[i]->getBow().getIntY() - (j+1)][units[i]->getBow().getX()] = status[dim - j - 1] ? (id + 32) : id;
            }
        } else {
            for (int j = 0; j < dim; j++) {
                output[units[i]->getStern().getIntY() - 1][units[i]->getStern().getX() + j] = status[j] ? (id + 32) : id;
            }
        }
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            os << output[i][j] << " ";
        }
        os << std::endl;
    }
}

void Controller::printAttack(std::ostream& os) {

    for (int i = 0; i < enemyEntities.size(); i++) {
        enemyEntitiesMatrix[enemyEntities[i]->getPos().getIntY() - 1][enemyEntities[i]->getPos().getX() - 1] = enemyEntities[i];
        std::cout << enemyEntities[i] << std::endl;
    }

    for (int i = 0; i < 13; i++) {
        if (i == 12) {
            for (char column : columns) {
                os << column << " ";
            }

        } else {
            for (int j = 0; j < 13; j++) {
                if (j == 0) {
                    os << rows[i] << " ";
                } else {
                    if (enemyEntitiesMatrix[i][j] == nullptr) {
                        os << "# ";
                    } else {
                        os << enemyEntitiesMatrix[i][j]->getId();
                        os << " ";
                    }
                }
            }
            os << "\n";
        }
    }
}

void Controller::print(std::ostream &os){
    
    /*
    for (int i = 0; i < enemyEntities.size(); i++) {
        enemyEntitiesMatrix[enemyEntities[i].getPos().getIntY() - 1][enemyEntities[i].getPos().getX() - 1] = &enemyEntities[i];
    }
    */
    char output[13][13] = {' '};
    
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 13; j++){
            output[i][j] = ' ';
        }
    }

    for (int i = 0; i < units.size(); i++) {
        std::vector<bool> status = units[i]->getStatus();
        int dim = units[i]->getDimension();
        char id = units[i]->getId();
        if ((*units[i]).isVertical()) {
            for (int j = 0; j < dim; j++) {
                output[units[i]->getStern().getIntY() + j - 1][units[i]->getStern().getX()] = status[j] ? (id + 32) : id;
            }
        } else {
            for (int j = 0; j < dim; j++) {
                output[units[i]->getStern().getIntY() - 1][units[i]->getStern().getX() + j] = status[j] ? (id + 32) : id;
            }
        }
    }
    
    for (int i = 0; i < 13; i++) {
        if (i == 12) {
            os << "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝";
            os << "        ";
            os << "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";
            os << "";
            for (char column : columns) {
                os << column << "   ";
            }
            os << "       ";
            for (char column : columns) {
                os << column << "   ";
            }
        } else {
            if (i == 0) {
                os << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗";
                os << "        ";
                os << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n";
            } else {
                os << "  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣";
                os << "        ";
                os << "  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n";
            }
            
            for (int j = 0; j < 13; j++) {
                if (j == 0) {
                    os << rows[i] << " ";
                } else {
                    os << "║ " << output[i][j] << " ";
                }
            }

            os << "║";
            os << "        ";
            int j = 0;
            for (j = 0; j < 13; j++){

                if (j == 0) {
                    os << rows[i] << " ";
                } else {
                    if (enemyEntitiesMatrix[i][j - 1] == nullptr) {
                        os << "   ";
                    } else {
                        os << " " << enemyEntitiesMatrix[i][j - 1]->getId();
                        os << " ";
                    }
                }
                os << "║";
            }
            
            os << "\n";
        }
        
    }
    os << "\n";
    
    /*
    for (int i = 0; i < units.size(); i++) {
        std::cout << units[i] << "\n";
    }
    for (int i = 0; i < enemyEntities.size(); i++) {
        std::cout << enemyEntities[i] << "\n";
    }
    std::cout << "\n";
    */
   
}

std::ostream& operator<<(std::ostream& os, Controller& a) {
    /* a.printDefense(os);
    os << std::endl;
    a.printAttack(os);
    */

    os << "\n";
    a.print(os);
    os << "\n";
    
    return os;
}

std::ostream& operator<<(std::ostream& os, Controller* a) {
    os << *a;
    return os;
}