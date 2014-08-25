#ifndef API_COMPONENT_ID_H
#define API_COMPONENT_ID_H

#include "entity/component.h"

using entity::HashableComponent;

namespace component {

/**
 * @brief Component for entities that have some (unique) id.
 *
 * This Component can be used to identify Entities by a number.
 * This number should be unique or pseudo-unique.
 */
class ID : public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(ID)
private:
    int _value;
public:
    /**
     * @brief Creates a new ID Component
     * @param id                - the id value
     * @param parent [optional] - the parent of this Component
     */
    explicit ID(int value, entity::Entity* parent = 0);
    /**
     * @brief Returns the id value of this ID Component
     */
    int getID() const { return _value; }

    virtual uint hash(uint seed) const;
};


} // namespace component

#endif // API_COMPONENT_ID_H
