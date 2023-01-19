// Enrico Zanoni

#include "Entity.h"

Entity::Entity() {
}

Entity::Entity(const Position &iPos, const char &iId) {
    id = iId;
    pos = iPos;
}

char Entity::getId() const {
    return id;
}

void Entity::setId(const char &iId) {
    id = iId;
}

Position Entity::getPos() const {
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