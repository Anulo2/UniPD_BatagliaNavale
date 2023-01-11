#include "Entity.h"

Entity::Entity() {
}

Entity::Entity(Position iPos, char iId) {
    id = iId;
    pos = iPos;
}

Entity::Entity(const Entity& a) {
    id = a.id;
    pos = a.pos;
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