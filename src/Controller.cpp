#include "Controller.h"

Controller::Controller() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            enemyEntitiesMatrix[i][j] = &defaultEntity;
        }
    }
}

bool Controller::isUnit(Position iPos) {
    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).containsPos(iPos)) {
            return true;
        }
    }
    return false;
}

std::vector<Unit*> Controller::getUnits() {
    return units;
}

Unit* Controller::getUnit(Position iPos) {
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->containsPos(iPos)) {
            return units[i];
        }
    }
    return nullptr;
}

std::vector<Unit*> Controller::getUnitsInRange(Position iPos, int range) {
    std::vector<Unit*> unitsInRange;

    Position a(iPos.getX() - range, iPos.getIntY() - range);
    Position b(iPos.getX() + range, iPos.getIntY() + range);

    for (int i = 0; i < units.size(); i++) {
        if ((*units[i]).getBow().isInside(a, b) || (*units[i]).getStern().isInside(a, b) || (*units[i]).getMiddle().isInside(a, b)) {  // DUBBIO SU VERIFICA: se range = 1 e nave è corazzata può succedere che ne prua ne poppa sono dentro ma qualche altra casella della nave si
            unitsInRange.push_back(units[i]);
        }
    }

    return unitsInRange;
}

bool Controller::checkUnitPlacement(Unit* iUnit) {
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

void Controller::addUnit(Unit* iUnit) {
    units.push_back(iUnit);
}

Controller::~Controller() {
}

void Controller::mergeEntities(std::vector<Entity> iEnemyEntities) {
    for (int i = 0; i < iEnemyEntities.size(); i++) {
        Position buffer = iEnemyEntities[i].getPos();
        if (!(enemyEntitiesMatrix[buffer.getIntY() - 1][buffer.getX() - 1]->isEmpty())) {
            Entity* bufferEntity = enemyEntitiesMatrix[buffer.getIntY() - 1][buffer.getX() - 1];
            // if(bufferEntity->getId()!= 'X'){
            bufferEntity->setId(iEnemyEntities[i].getId());
            //}
        } else {
            enemyEntitiesMatrix[buffer.getIntY() - 1][buffer.getX() - 1] = &iEnemyEntities[i];
            enemyEntities.push_back(iEnemyEntities[i]);
        }
    }
}

char columns[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void Controller::printDefense(std::ostream& os) {  // Forse si può evitare il dopddio n^2 e farlo solo una volta, per ora va bene così
    char output[13][13];
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (j == 0) {
                output[i][j] = rows[11 - i];
            } else {
                output[i][j] = '#';
            }
        }
    }

    std::copy(columns, columns + 13, output[12]);

    for (int i = 0; i < units.size(); i++) {
        std::vector<char> status = units[i]->getStatus();
        std::cout << units[i] << ", " << units[i]->getStern() << ", " << units[i]->getBow() << "\n";
        int dim = units[i]->getDimension();
        if ((*units[i]).isVertical()) {
            for (int j = 0; j < dim; j++) {
                output[12 - units[i]->getBow().getIntY() + j][units[i]->getBow().getX()] = status[dim - j - 1];
            }
        } else {
            for (int j = 0; j < dim; j++) {
                output[12 - units[i]->getStern().getIntY()][units[i]->getStern().getX() + j + 1] = status[j];
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
        enemyEntitiesMatrix[12 - enemyEntities[i].getPos().getIntY()][enemyEntities[i].getPos().getX() - 1] = &enemyEntities[i];
        // std::cout << enemyEntities[i] << std::endl;
    }

    for (int i = 0; i < 13; i++) {
        if (i == 12) {
            for (char column : columns) {
                os << column << " ";
            }

        } else {
            for (int j = 0; j < 13; j++) {
                if (j == 0) {
                    os << rows[11 - i] << " ";
                } else {
                    if (enemyEntitiesMatrix[i][j - 1]->isEmpty()) {
                        os << "# ";
                    } else {
                        os << enemyEntitiesMatrix[i][j - 1]->getId();
                        os << " ";
                    }
                }
            }
            os << "\n";
        }
    }
}

std::ostream& operator<<(std::ostream& os, Controller& a) {
    a.printDefense(os);
    os << std::endl;
    a.printAttack(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, Controller* a) {
    os << *a;
    return os;
}