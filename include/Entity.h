#ifndef ENTITY_H
#define ENTITY_H

#include "Position.h"

class Entity {
   public:
    Entity(Position iPos, char iId);
    Position getPos();
    char getId();

    ~Entity();

   private:
    char id;
    Position pos;
};

#endif