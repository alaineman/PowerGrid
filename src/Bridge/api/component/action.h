#ifndef API_COMPONENT_ACTION_H
#define API_COMPONENT_ACTION_H

#include "entity/component.h"
#include "entity/entity.h"

namespace api {
namespace component {

using entity::Component;
using entity::Entity;
using java::lang::Object;

/**
    \brief Action that operates on Objects of a specific \c Type.

    This class models an Action that is performed on an Object in the
    Runescape world. This class provides a way to include actions in
    the Entities themselves as properties.
 */
class Action : public Component {
    Q_OBJECT
public:
    /**
        \brief Creates a new Action object

        The reference may be referring to a Java null-pointer,
        and the parent can also be NULL.

        \param ref the referenced Java Object
        \param parent the parent QObject
     */
    Action(Object ref, Entity *parent = Q_NULLPTR);

    /**
        \brief Executes the action on the provided Entity

        This operation is allowed to throw any kind of
        exception when the operation fails.
        \param e the Entity* to execute the action on
     */
    virtual void execute(Entity* e) = 0;

    /**
        \brief Compares this Action to another for equality

        \param other the Action to compare with
        \return true if this Action is equal to the other, false otherwise
     */
    bool operator== (const Action& other);
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_ACTION_H
