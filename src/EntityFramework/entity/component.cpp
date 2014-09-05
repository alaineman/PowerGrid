#include "component.h"
#include "entity.h"

namespace entity {

Component::Component(Entity* parent) : QObject(parent) {
    if (parent != NULL) {
        parent->addComponent(this);
    }
}

}

uint qHash(entity::HashableComponent* key, uint seed) {
    return key == 0 ? 0 : key->hash(seed);
}
