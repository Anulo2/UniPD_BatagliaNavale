// Enrico Zanoni

#ifndef ENTITY_H
#define ENTITY_H

#include <ostream>

#include "Position.h"

class Entity {
public:
    Entity();                        // costruttore di default
    Entity(Position iPos, char iId); // costruttore
    Position getPos() const;         // getter della posizione
    char getId() const;              // getter identificativo
    void setId(char iId);            // setter identificativo

private:
    char id = ' ';
    Position pos;
};
std::ostream &operator<<(std::ostream &os, Entity &a);
std::ostream &operator<<(std::ostream &os, Entity *a);
bool operator==(Entity a, Entity b);
bool operator!=(Entity a, Entity b);
#endif