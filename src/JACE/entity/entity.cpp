#include "entity.h"
#include "world.h"

namespace entity {

Entity::Entity(QObject *parent) : QObject(parent) {
    World* world = qobject_cast<World*>(parent);
    if (world != NULL) {
        world->addEntity(this);
    }
}

}
