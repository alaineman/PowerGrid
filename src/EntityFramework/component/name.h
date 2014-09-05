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
#ifndef COMPONENT_NAME_H
#define COMPONENT_NAME_H

#include "entity/component.h"
#include "jace/JField.h"
#include "java/lang/string.h"

using entity::HashableComponent;
using jace::JField;

namespace component {

/**
 * @brief Component for entities with a name
 *
 * The name should be descriptive and (usually) human-readable.
 */
class Name: public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(Name)
private:
    QString value;
public:
    /**
     * @brief Creates a new Name Component
     * @param name              - the name
     * @param parent [optional] - the parent of this Component
     */
    Name(QString name, entity::Entity *parent = 0);
    /**
     * @brief Returns the name value of this Name Component
     */
    QString getName() const { return value; }

    virtual uint hash(uint seed) const;
};

} // namespace component

#endif // COMPONENT_NAME_H
