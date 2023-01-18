// Enrico Zanoni

#ifndef ENTITY_H
#define ENTITY_H

#include <ostream>

#include "Position.h"

class Entity {
   public:
    Entity();
    Entity(Position iPos, char iId);
    // Entity(const Entity &a);
    Position getPos();
    char getId();
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