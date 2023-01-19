// Enrico Zanoni

#ifndef ENTITY_H
#define ENTITY_H

#include <ostream>

#include "Position.h"

class Entity {
   public:
    // costruttore di default
    Entity();

    // costruttore
    Entity(Position iPos, char iId);

    // getter della posizione
    Position getPos() const;

    // getter identificativo
    char getId() const;

    // setter identificativo
    void setId(char iId);

   private:
    char id = ' ';
    Position pos;
};
std::ostream &operator<<(std::ostream &os, Entity &a);
std::ostream &operator<<(std::ostream &os, Entity *a);
bool operator==(Entity a, Entity b);
bool operator!=(Entity a, Entity b);
#endif