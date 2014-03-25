#include "mapper.h"
#include "world.h"

namespace entity {

Mapper::Mapper(QString type, World* parent) : QObject(parent), type(type) {
    if (parent == NULL) {
        throw std::runtime_error("NULL world is not allowed");
    }

    // Connect to the specified World.
    connect(parent, SIGNAL(componentAdded(Entity*,Component*)), this, SLOT(add(Entity*,Component*)));
    connect(parent, SIGNAL(componentRemoved(Entity*,Component*)), this, SLOT(remove(Entity*,Component*)));
}

bool Mapper::contains(Entity* e) const{
    Component* cmp = e->get(type);
    if (cmp) {
        return *(map.find(cmp)) == e;
    } else {
        // if the entity doesn't have the expected Component type,
        // it cannot be in this Mapper
        return false;
    }
}

Entity* Mapper::getEntity(Component* key) const {
    if (key->metaObject()->className() != type) {
        return NULL;
    }
    return map.value(key, NULL);
}

QString Mapper::getMappedType() const {
    return type;
}

void Mapper::remove(Entity* e, Component* cmp){
    if (e != NULL && getEntity(cmp) == e) {
        map.remove(cmp);
    }
}

void Mapper::add(Entity* e, Component* cmp){
    if (cmp->metaObject()->className() == type) {
        map.insert(cmp, e);
    }
}

} // namespace entity
