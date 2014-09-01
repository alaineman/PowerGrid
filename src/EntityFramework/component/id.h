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
#ifndef COMPONENT_ID_H
#define COMPONENT_ID_H

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

#endif // COMPONENT_ID_H
