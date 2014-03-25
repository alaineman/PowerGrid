#include "entity.h"
#include "world.h"
#include "component.h"

#include <QMap>

namespace entity {

Entity::Entity(QObject *parent) : QObject(parent){
    World* world = qobject_cast<World*>(parent);
    if (world != NULL) {
        world->addEntity(this);
    }
}

template<typename Type> Type* Entity::get(){
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
        int result = components.remove(cmp->metaObject()->className());
        if (result > 0) {
            emit componentRemoved(this, cmp);
        }
    }
}

}
