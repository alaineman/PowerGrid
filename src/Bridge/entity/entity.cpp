#include "entity.h"
#include "world.h"
#include "component.h"

#include <QMap>

namespace entity {

Entity::Entity(World *world) : QObject(world){
    if (world != NULL) {
        world->addEntity(this);
    } else {
        throw std::logic_error("World cannot be NULL");
    }
}

template<typename Type>
Type* Entity::get(){
    return qobject_cast<Type*>(get(Type::staticMetaObject.className()));
}

Component* Entity::get(QString name){
    QMap<QString, Component*>::Iterator it = components.find(name);
    if (it == components.end()) {
        return NULL;
    } else {
        return (*it);
    }
}

template<typename Type> bool Entity::has(){
    return has(Type::staticMetaObject.className());
}

bool Entity::has(QString name){
    return components.contains(name);
}

void Entity::addComponent(Component *cmp, bool overwrite) {
    if (cmp != NULL) {
        Component* orig = get(cmp->metaObject()->className());
        if (overwrite && orig != NULL) {
            components.remove(cmp->metaObject()->className());
            emit componentRemoved(this, orig);
        }
        if (overwrite || orig == NULL) {
            components.insert(cmp->metaObject()->className(), cmp);
            emit componentAdded(this, cmp);
        }
    }
}

void Entity::removeComponent(Component *cmp) {
    if (cmp != NULL)  {
        Component* val = components.value(cmp->metaObject()->className());
        if (cmp == val) {
            components.remove(cmp->metaObject()->className());
            emit componentRemoved(this, cmp);
        }
    }
}

}
