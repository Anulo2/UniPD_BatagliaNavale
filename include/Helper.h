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

enum unitType : int {
    random_battleship,
    random_support,
    random_submarine,
    iBattleship,
    iSupport,
    iSubmarine,
};

void writeLog(std::ostream &os, std::vector<std::string> log); // scrive il log sullo stream dato

std::string addContentToLog(std::shared_ptr<Unit> obj); // aggiunge il contenuto al log

std::string addContentToLog(Position target, std::string actionUnit); // aggiunge il contenuto al log

std::string logToString(std::vector<std::string> log); // conversione da log a string

std::string getPlayerInput(std::istream &is); // restituisce una stringa dal input stream del player

std::vector<Position> inputString(std::string in); // restituisce una posizione dall'input stream

int stringTointeger(const std::string str); // conversione string -> int

std::shared_ptr<Battleship> inputBattleship(std::string in); // data una stringa dallo stream di input restituisce un battleship

std::shared_ptr<Support> inputSupport(std::string in); // data una stringa dallo stream di input restituisce un supporto

std::shared_ptr<Submarine> inputSubmarine(std::string in); // data una stringa dallo stream di input restituisce un sottomarino

std::shared_ptr<Unit> randomBattleship(); // restituisce un battleship random

std::shared_ptr<Unit> randomSupport(); // restituisce un supporto random

std::shared_ptr<Unit> randomSubmarine(); // restituisce un sottomarino random

std::shared_ptr<Unit> typeOfUnit(Helper::unitType unitType); // seleziona il tipo di unità da piazare

std::shared_ptr<Unit> typeOfUnit(Helper::unitType unitType, std::string inString);

std::string randomAction(Controller *player1, Controller *player2); // player 1 performa un azione random + merge entity

std::string handlePlayerAction(Controller *player1, Controller *player2, std::string iLogStr); // Gestisce l'acquisizione dell'azione del player

} // namespace Helper

#endif // HELPER_H