#ifndef API_COMPONENT_NAME_H
#define API_COMPONENT_NAME_H

#include "entity/component.h"
#include "jace/JField.h"
#include "java/lang/string.h"

using entity::HashableComponent;
using jace::JField;

namespace api {
namespace component {

/**
 * @brief Component for entities with a name
 *
 * The name should be descriptive and (usually) human-readable.
 */
class Name: public HashableComponent {
    Q_OBJECT
private:
    JField<java::lang::String> value;
public:
    /**
     * @brief Creates a new Name Component
     * @param ref the reference Object
     * @param name the JField containing the name
     * @param parent the parent of this Component
     */
    Name(Object ref, JField<java::lang::String> name, entity::Entity *parent = 0);
    /**
     * @brief Returns the name value of this Name Component
     */
    QString getName() const;

    virtual uint hash(uint seed) const;
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_NAME_H
