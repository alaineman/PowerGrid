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
#ifndef COMPONENT_INTERACTION_H
#define COMPONENT_INTERACTION_H

#include "entity/component.h"
#include <QMap>

using entity::Component;

namespace component {

class Action;

/**
 * \brief Adds interactions to an Entity.
 *
 * This Component type can be used to assign actions to Entities.
 * These actions can relate to actual actions available in the
 * Runescape client, or actions added by PowerGrid (or any of its Plugins).
 */
class Interaction : public Component {
    Q_OBJECT
    Q_DISABLE_COPY(Interaction)
private:
    QMap<QString, Action*> actions;
public:
    /**
     * @brief Creates a new Interaction Component
     * @param _actions the actions that can be performed
     * @param parent [optional] - the parent of this Component
     */
    explicit Interaction(QMap<QString, Action*> _actions,
                         entity::Entity *parent = 0);

    /**
     * @brief Returns the Action* with the given name.
     *
     * If no Action exists with that name, a NULL pointer is
     * returned.
     * @param name the name of the requested Action
     * @return the Action, or NULL if it doesn't exist.
     */
    Action* getAction(QString name) const;
    /**
     * @brief Returns a QMap with all available Actions
     *
     * The returned QMap maps the name of the Action to the
     * Action*.
     * @return a QMap with the available Actions.
     */
    QMap<QString, Action*> getActionMap() const;

};
} // namespace component

#endif // COMPONENT_INTERACTION_H
