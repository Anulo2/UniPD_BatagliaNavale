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
            std::cout << "Removed Unit: " << units[i] << "\n";

            if (units.size() == 1) {
                dead = true;
                return;
            }

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

bool Controller::isDead() {
    return dead;
}
std::vector<std::shared_ptr<Unit>> Controller::getUnitsInRange(Position iPos, int range) {
    std::vector<std::shared_ptr<Unit>> unitsInRange;

    Position a(std::max(iPos.getX() - range, 1), std::max(iPos.getIntY() - range, 1));
    Position b(std::min(iPos.getX() + range, 12), std::min(iPos.getIntY() + range, 12));

    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).getBow().isInside(a, b) || (*units[i]).getStern().isInside(a, b) || (*units[i]).getMiddle().isInside(a, b)) {  // DUBBIO SU VERIFICA: se range = 1 e nave è corazzata può succedere che ne prua ne poppa sono dentro ma qualche altra casella della nave si
            unitsInRange.push_back(units[i]);
        }
    }

    return unitsInRange;
}

bool Controller::checkUnitPlacement(std::shared_ptr<Unit> originalUnit, std::shared_ptr<Unit> iUnit) {
    Position a(1, 1);
    Position b(12, 12);
    if (iUnit->getBow().isInside(a, b) && iUnit->getStern().isInside(a, b)) {
        std::vector<Position> buffer = iUnit->getUnitPositions();
        for (int i = 0; i < units.size(); i++) {
            if (units[i] != originalUnit) {
                for (int j = 0; j < buffer.size(); j++) {
                    if (units[i]->containsPos(buffer[j])) {
                        return false;
                    }
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
            enemyEntitiesMatrix[iEnemyEntities[i]->getPos().getIntY() - 1][iEnemyEntities[i]->getPos().getX() - 1]->setId(iEnemyEntities[i]->getId());

        } else {
            std::shared_ptr<Entity> sharedPtr(iEnemyEntities[i]);
            enemyEntities.push_back(sharedPtr);
            enemyEntitiesMatrix[sharedPtr->getPos().getIntY() - 1][sharedPtr->getPos().getX() - 1] = sharedPtr;
        }
    }
}

void Controller::clearAttackGrid(const char x) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (enemyEntitiesMatrix[i][j] != nullptr) {
                if (enemyEntitiesMatrix[i][j]->getId() == x) {
                    enemyEntitiesMatrix[i][j]->setId(' ');

                } else if (x == ' ') {
                    enemyEntitiesMatrix[i][j]->setId(' ');
                }
            }
        }
    }

    if (x == 'X')
        std::cout << "\nAll the hits 'X' have been removed\n";
    else if (x == 'O')
        std::cout << "\nAll the miss 'O' have been removed\n";
    else if (x == ' ')
        std::cout << "\nThe attack gris is clear\n";
}

std::string columns[] = {" ", "  1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 ", "10 ", "11 ", "12 "};

void Controller::printDefense(std::ostream &os) {  // Forse si può evitare il dopddio n^2 e farlo solo una volta, per ora va bene così
    std::string output[13][13];
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

        int dim = units[i]->getDimension();
        char id = units[i]->getId();
        if ((*units[i]).isVertical()) {
            for (int j = 0; j < dim; j++) {
                output[units[i]->getBow().getIntY() - (j + 1)][units[i]->getBow().getX()] = status[dim - j - 1] ? (id + 32) : id;
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

void Controller::printAttack(std::ostream &os) {
    for (int i = 0; i < enemyEntities.size(); i++) {
        enemyEntitiesMatrix[enemyEntities[i]->getPos().getIntY() - 1][enemyEntities[i]->getPos().getX() - 1] = enemyEntities[i];
        std::cout << enemyEntities[i] << std::endl;
    }

    for (int i = 0; i < 13; i++) {
        if (i == 12) {
            for (int j = 0; j < 13; j++) {
                os << columns[j] << " ";
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

void Controller::print(std::ostream &os) {
    char output[13][13] = {' '};

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
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
            for (int j = 0; j < 13; j++) {
                os << columns[j] << " ";
            }
            os << "        ";
            for (int j = 0; j < 13; j++) {
                os << columns[j] << " ";
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
            for (j = 0; j < 13; j++) {
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
}

std::ostream &operator<<(std::ostream &os, Controller &a) {
    os << "\n";
    a.print(os);
    os << "\n";

    return os;
}

std::ostream &operator<<(std::ostream &os, Controller *a) {
    os << *a;
    return os;
}