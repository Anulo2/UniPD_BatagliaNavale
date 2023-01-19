// Eris Sanson

#ifndef GAME_H
#define GAME_H

#include <ostream>

#include "Helper.h"

class Game {
public:
    Game(); // costruttore di default

    Controller *getPlayer1(); // getter player1
    Controller *getPlayer2(); // getter player2

    virtual void startGame(); // funzione virtuale per piazzare le unità e iniziare il gioco

    std::vector<std::string> getLog();          // getter del log
    void addToLog(std::shared_ptr<Entity> obj); // aggiunge al log
    void addStringToLog(std::string iLog);      // aggiunge stringa al log
    int getStartingPlayer();                    // getter del giocatore iniziale

    bool placeUnit(Controller &player, Helper::unitType unitType);                       // piazza un'unità del tipo specificato sul controller dato
    void placeUnit(Controller &player, Helper::unitType unitType, std::string inString); // piazza un'unità del tipo specificato sul controller dato
    void placeUnits(Controller &player, Helper::unitType unitType, int quantity);        // piazza quantity unità del tipo specificato sul controller dato

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