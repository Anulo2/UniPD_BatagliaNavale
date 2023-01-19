// Eris Sanson

#ifndef GAME_H
#define GAME_H

#include <ostream>

#include "Helper.h"

class Game {
   public:
    // costruttore di default
    Game();

    // getter player1
    Controller *getPlayer1();

    // getter player2
    Controller *getPlayer2();

    // funzione virtuale per piazzare le unità, necessaria per iniziare il gioco
    virtual void startGame();

    // getter del log
    std::vector<std::string> getLog();

    // aggiunge al log in base a un Entity
    void addToLog(std::shared_ptr<Entity> obj);

    // aggiunge stringa al log
    void addStringToLog(std::string iLog);

    // getter del giocatore iniziale
    int getStartingPlayer();

    // piazza un'unità del tipo specificato sul controller dato
    bool placeUnit(Controller &player, Helper::unitType unitType);

    // piazza un'unità del tipo specificato sul controller dato
    void placeUnit(Controller &player, Helper::unitType unitType, std::string inString);

    // piazza quantity unità del tipo specificato sul controller dato
    void placeUnits(Controller &player, Helper::unitType unitType, int quantity);

   protected:
    Controller player1;
    Controller player2;
    int selectPlayer;
    std::vector<std::string> log;
};

// overload operatori
std::ostream &operator<<(std::ostream &os, Entity &a);
std::ostream &operator<<(std::ostream &os, Entity *a);
bool operator==(Entity a, Entity b);
bool operator!=(Entity a, Entity b);
#endif