#ifndef API_COMPONENT_ID_H
#define API_COMPONENT_ID_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::HashableComponent;
using jace::JField;

namespace api {
namespace component {

/**
 * @brief Component for entities that have some (unique) id.
 *
 * This Component can be used to identify Entities by a number.
 * This number should be unique or pseudo-unique.
 */
class ID : public HashableComponent {
    Q_OBJECT
private:
    JField<JInt> value;
public:
    /**
     * @brief Creates a new ID Component
     * @param ref the reference Object
     * @param id the JField containing the id value
     * @param parent the parent of this Component
     */
    explicit ID(Object ref, JField<JInt> id, entity::Entity* parent = 0);
    /**
     * @brief Returns the id value of this ID Component
     */
    int getID() const;

    virtual uint hash(uint seed) const;
};


} // namespace component
} // namespace api

#endif // API_COMPONENT_ID_H
