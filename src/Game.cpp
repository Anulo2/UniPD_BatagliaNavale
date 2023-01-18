// Eris Sanson

#include "Game.h"

/*********************************************************
 *                    CONSTRUCTOR                        *
 **********************************************************/
Game::Game() {
}

/*********************************************************
 *                  GETTER FUNCTIONS                     *
 **********************************************************/

Controller* Game::getPlayer1() {
    return &player1;
}

Controller* Game::getPlayer2() {
    return &player2;
}

std::vector<std::string> Game::getLog() {
    std::vector<std::string> buffer = log;
    log.clear();
    return buffer;
}

/*********************************************************
 *                  SETTER FUNCTIONS                     *
 **********************************************************/

bool Game::placeUnit(Controller& player, Helper::unitType unitType) {
    bool unitPlaced = false;
    try {
        std::shared_ptr<Unit> buffer(Helper::typeOfUnit(unitType));

        if (player.checkUnitPlacement(buffer, buffer)) {
            player.addUnit(buffer);
            unitPlaced = true;

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
    return unitPlaced;
}

void Game::placeUnit(Controller& player, Helper::unitType unitType, std::string inString) {
    std::shared_ptr<Unit> buffer(Helper::typeOfUnit(unitType, inString));

    if (player.checkUnitPlacement(buffer, buffer)) {
        player.addUnit(buffer);

        log.push_back(inString);
    } else {
        std::cout << "Invalid input, There is already a ship\n";
    }
}

void Game::placeUnits(Controller& player, Helper::unitType unitType, int quantity) {
    for (int i = 0; i < quantity; i++) {
        while (!placeUnit(player, unitType)) {
        }

        std::cout << "Placed Unit Player!\n";
        if(i < quantity-1){
            std::cout << "Place next unit!\n";
        }
    }
}

void Game::addToLog(std::shared_ptr<Entity> obj) {
    std::string coordBow = obj->getPos().getY() + std::to_string(obj->getPos().getX());
    std::string coordStern = obj->getPos().getY() + std::to_string(obj->getPos().getX());
    log.push_back(coordStern + " " + coordBow);
}

void Game::addStringToLog(std::string iLog) {
    log.push_back(iLog);
}

int Game::getStartingPlayer() {
    return selectPlayer;
}

/*********************************************************
 *                  HELPER FUNCTIONS                     *
 **********************************************************/

std::ostream& operator<<(std::ostream& os, Game& a) {
    // Helper::writeLog(os,a.getLog());

    os << (a.getPlayer1());
    os << "\n";
    os << (a.getPlayer2());
    return os;
}

std::ostream& operator<<(std::ostream& os, Game* a) {
    os << *a;
    return os;
}
