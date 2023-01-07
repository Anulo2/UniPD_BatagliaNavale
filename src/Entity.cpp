#include "Entity.h"

Entity::Entity(Position iPos, char iId) {
    id = iId;
    pos = iPos;
}

char Entity::getId() {
    return id;
}

Position Entity::getPos() {
    return pos;
}

Entity::~Entity() {
}

std::ostream& operator<<(std::ostream& os, Entity& a) {
    os << "(" << a.getPos() << ", " << a.getId() << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, Entity* a) {
    os << *a;
    return os;
}