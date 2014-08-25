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
 * Components are usually immutable, allowing them to be shared
 * across different Entities.
 *
 * \author Patrick Kramer
 */
class Component : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Component)
public:
    /**
     * \brief Creates a new Component with the given parent
     *
     * If the parent is an Entity, the newly created Component is directly
     * assigned to that Entity.
     *
     * \param parent - the parent of this Component
     */
    explicit Component(Entity* parent = 0);
};

/**
 * @brief Component subclass for hashable Component types.
 *
 * The Entity framework will automatically use hash-based data structures for
 * storing Component types that extend from this class. This improves the
 * performance of (for example) Mapper operations.
 */
class HashableComponent : public Component {
    Q_OBJECT
    Q_DISABLE_COPY(HashableComponent)
public:
    /**
     * \brief Creates a new HashableComponent with the given parent
     *
     * If the parent is an Entity, the newly created HashableComponent is directly
     * assigned to that Entity.
     *
     * \param parent - the parent of this HashableComponent
     */
    explicit HashableComponent(Entity* parent = 0) :
        Component(parent) {}

    /**
     * @brief Returns a hash code for this object using the provided seed.
     *
     * To assert the correctness of this hash code, it must hold that the
     * value returned by this function for a given seed stays the same
     * over the lifetime of this object.
     *
     * For efficiency, it is advised for two HashableComponents @c a and @c b,
     * that if @c a!=b, then @c a.hash(s)!=b.hash(s) for any seed @c s, for as
     * far as this is possible.
     *
     * @param seed - the seed to use while computing the hash
     * @return the computed hash code
     */
    virtual uint hash(uint seed) const = 0;
};

}

/**
 * @brief Hash function for HashableComponent objects.
 * @param key  - the HashableComponent to hash
 * @param seed - the seed to use for hashing
 * @return a hash code corresponding with the provided arguments.
 */
uint qHash(entity::HashableComponent* key, uint seed);

/**
 * @brief bitwise-rotates the value @c amount bits to the left.
 * @param val    - the value to rotate, must be an integer type.
 * @param amount - the amount of bits to rotate
 */
template<typename T>
T rol(T val, uint amount) {
    return (val << amount) | (val >> (sizeof(T)*8 - amount));
}

/**
 * @brief bitwise-rotates the value @c amount bits to the right.
 * @param val    - the value to rotate, must be an integer type.
 * @param amount - the amount of bits to rotate
 */
template<typename T>
T ror(T val, uint amount) {
    return (val >> amount) | (val << (sizeof(T)*8 - amount));
}

#endif // COMPONENT_H
