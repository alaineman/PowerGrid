#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

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
public:
    /**
     * \brief Creates a new Component with the given parent
     *
     * If the parent is an Entity, the newly created Component is directly
     * assigned to that Entity.
     * \param parent the parent of this Component
     */
    explicit Component(Entity* parent = 0);
};

class HashableComponent : public Component {
    Q_OBJECT
public:
    explicit HashableComponent(Entity* parent = 0) :
        Component(parent) {}

    virtual uint hash(uint seed) const = 0;
};

}

uint qHash(entity::HashableComponent* key, uint seed);

template<typename T>
T rol(T val, uint amount) {
    return (val << amount) | (val >> (sizeof(T)*8 - amount));
}

template<typename T>
T ror(T val, uint amount) {
    return (val >> amount) | (val << (sizeof(T)*8 - amount));
}

#endif // COMPONENT_H
