// Enrico Zanoni

#include "Entity.h"

Entity::Entity() {
}

Entity::Entity(Position iPos, char iId) {
    id = iId;
    pos = iPos;
}

char Entity::getId() {
    return id;
}

void Entity::setId(char iId) {
    id = iId;
}

Position Entity::getPos() {
    return pos;
}

std::ostream &operator<<(std::ostream &os, Entity &a) {
    os << "(" << a.getPos() << ", " << a.getId() << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, Entity *a) {
    os << *a;
    return os;
}
bool operator==(Entity a, Entity b) {
    return (a.getPos() == b.getPos()) && (a.getId() == b.getId());
}
bool operator!=(Entity a, Entity b) {
    return !(a == b);
}