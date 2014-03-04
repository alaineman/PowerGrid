#include "component.h"
#include "entity.h"

namespace entity {

Component::Component(QObject *parent) :
    QObject(parent) {
    Entity* e = qobject_cast<Entity*>(parent);
    if (e != NULL) {
        e->addComponent(this);
    }
}

}
