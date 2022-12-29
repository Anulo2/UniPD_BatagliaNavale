#include "Entity.h"

Entity::Entity(Position iPos, char iId){
    id = iId;
    pos = iPos;
}

char Entity::getId(){
    return id;
}

Position Entity::getPos(){
    return pos;
}
