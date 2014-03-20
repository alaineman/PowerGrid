#include "mapper.h"
#include "world.h"

namespace entity {

Mapper::Mapper(World* parent) : QObject(parent){
    if (parent == NULL) {
        throw std::runtime_error("NULL world is not allowed");
    }

    // Connect to the specified World.
    connect(parent, SIGNAL(componentAdded(Entity*,Component*)), this, SLOT(add(Entity*,Component*));
    connect(parent, SIGNAL(componentRemoved(Entity*,Component*)), this, SLOT(remove(Entity*,Component*));
}

bool Mapper::contains(Entity* e){
    return false;
}

Entity* Mapper::getEntity(Key key){
    return NULL;
}

void Mapper::remove(Entity* e, Component* cmp){

}

void Mapper::add(Entity* e, Component* cmp){

}

} // namespace entity
