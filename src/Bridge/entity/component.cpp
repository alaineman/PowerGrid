#include "component.h"
#include "entity.h"

using java::lang::Object;

namespace entity {

Component::Component(Object ref, QObject* parent) : QObject(parent), obj(ref)  {
    Entity* e = qobject_cast<Entity*>(parent);
    if (e != NULL) {
        e->addComponent(this);
    }
}

Object Component::getReference() const {
    return obj;
}

}
