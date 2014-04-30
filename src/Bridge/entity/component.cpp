#include "component.h"
#include "entity.h"

using java::lang::Object;

namespace entity {

Component::Component(Object ref, Entity* parent) : QObject(parent), obj(ref)  {
    if (parent != NULL) {
        parent->addComponent(this);
    }
}

Object Component::getReference() const {
    return obj;
}

}

uint qHash(entity::HashableComponent* key, uint seed) {
    return key == 0 ? 0 : key->hash(seed);
}
