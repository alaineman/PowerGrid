/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
