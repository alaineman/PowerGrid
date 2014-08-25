#ifndef COMPONENT_ACTION_H
#define COMPONENT_ACTION_H

#include "entity/component.h"
#include "entity/entity.h"

namespace component {

using entity::Component;
using entity::Entity;

/**
    \brief Action that operates on Objects of a specific \c Type.

    This class models an Action that is performed on an Entity.
    This class provides a way to include actions in the Entities
    themselves as properties.
 */
class Action : public Component {
    Q_OBJECT
    Q_DISABLE_COPY(Action)
public:
    /**
        \brief Creates a new Action object

        The parent may be NULL, in which case the Component is not (yet) assigned to any Entity.

        \param parent [optional] - the parent QObject
     */
    Action(Entity *parent = Q_NULLPTR);

    /**
        \brief Executes the action on the provided Entity

        This operation is allowed to throw any kind of
        exception when the operation fails.

        \param e - the Entity* to execute the action on
     */
    virtual void execute(Entity* e) = 0;
};

} // namespace component

#endif // COMPONENT_ACTION_H
