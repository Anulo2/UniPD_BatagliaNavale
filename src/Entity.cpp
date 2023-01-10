#include "Entity.h"

Entity::Entity() {
}

Entity::Entity(Position iPos, char iId) {
    id = iId;
    pos = iPos;
    empty = false;
}

Entity::Entity(const Entity& a) {
    id = a.id;
    pos = a.pos;
    empty = a.empty;
}

char Entity::getId() {
    return id;
}

bool Entity::isEmpty() {
    return empty;
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