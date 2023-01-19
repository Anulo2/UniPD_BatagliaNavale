// Enrico Zanoni

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <random>

#include "Battleship.h"
#include "Controller.h"
#include "Submarine.h"
#include "Support.h"

namespace Helper {

// Enumerazione dei tipi delle unitá disponibili
enum unitType : int {
    random_battleship,
    random_support,
    random_submarine,
    iBattleship,
    iSupport,
    iSubmarine,
};

// scrive il log sullo stream dato
void writeLog(std::ostream &os, const std::vector<std::string> log);

// aggiunge il contenuto al log
std::string addContentToLog(std::shared_ptr<Unit> obj);

// aggiunge il contenuto al log
std::string addContentToLog(const Position& target, const std::string& actionUnit);

// conversione da log a string
std::string logToString(std::vector<std::string> log);

// restituisce una stringa dal input stream del player
std::string getPlayerInput(std::istream &is);

// restituisce una posizione dall'input stream
std::vector<Position> inputString(const std::string& in);

// conversione string -> int
int stringTointeger(const std::string& str);

// data una stringa dallo stream di input restituisce un battleship
std::shared_ptr<Battleship> inputBattleship(const std::string& in);

// data una stringa dallo stream di input restituisce un supporto
std::shared_ptr<Support> inputSupport(const std::string& in);

// data una stringa dallo stream di input restituisce un sottomarino
std::shared_ptr<Submarine> inputSubmarine(const std::string& in);

// restituisce un battleship random
std::shared_ptr<Unit> randomBattleship();

// restituisce un supporto random
std::shared_ptr<Unit> randomSupport();

// restituisce un sottomarino random
std::shared_ptr<Unit> randomSubmarine();

// seleziona il tipo di unità da piazare
std::shared_ptr<Unit> typeOfUnit(const Helper::unitType& unitType);

// seleziona il tipo di unità da piazare
std::shared_ptr<Unit> typeOfUnit(const Helper::unitType& unitType, const std::string& inString);

// player 1 performa un azione random + merge entity
std::string randomAction(Controller *player1,Controller *player2);

// Gestisce l'acquisizione dell'azione del player
std::string handlePlayerAction(Controller *player1, Controller *player2, const std::string& iLogStr);

}  // namespace Helper

#endif  // HELPER_H