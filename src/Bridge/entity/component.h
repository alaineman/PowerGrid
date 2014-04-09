#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include "java/lang/object.h"

using java::lang::Object;

namespace entity {

class Entity;

/**
 * \brief Base class for all components.
 *
 * Components are assigned to Entities to give them properties.
 * The Component class by itself does not define any properties.
 * As such, directly creating a Component instance is usually
 * pointless.
 *
 * \author Patrick Kramer
 */
class Component : public QObject {
    Q_OBJECT
private:
    Object obj;
public:
    /**
     * \brief Creates a new Component with the given parent
     *
     * If the parent is an Entity, the newly created Component is directly
     * assigned to that Entity.
     * \param parent the parent of this Component
     */
    explicit Component(Object ref, Entity* parent = 0);

    /**
     * @brief Returns the reference of this Component
     *
     * Note that not all Components may make use of reference Objects, and
     * they may return null-Objects (Objects for which @c Object::isNull()
     * returns @c true).
     */
    Object getReference() const;

};

class HashableComponent : public Component {
public:
    explicit HashableComponent(Object ref, Entity* parent = 0);

    virtual uint hash(uint seed) const = 0;

    bool operator ==(const HashableComponent& other) const {
        return getReference() == other.getReference();
    }
};

}

uint qHash(entity::HashableComponent* key, uint seed) {
    return key == 0 ? 0 : key->hash(seed);
}

template<typename T>
T rol(T val, uint amount) {
    return (val << amount) | (val >> (sizeof(T)*8 - amount));
}

template<typename T>
T ror(T val, uint amount) {
    return (val >> amount) | (val << (sizeof(T)*8 - amount));
}

#endif // COMPONENT_H
