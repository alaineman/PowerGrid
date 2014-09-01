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
#ifndef COMPONENT_POSITION_H
#define COMPONENT_POSITION_H

#include "entity/component.h"

using entity::HashableComponent;

namespace component {

/**
 * @brief Component for Entities with a position.
 *
 * This Component type represents a point in 3D space with
 * integer coordinates.
 */
class Position : public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(Position)
private:
    int _x, _y, _z;
public:
    /**
     * @brief Creates a new Position instance with the specified coordinates
     * @param x                 - the x coordinate
     * @param y                 - the y coordinate
     * @param z                 - the z coordinate
     * @param parent [optional] - the parent Entity
     */
    Position(int x, int y, int z, entity::Entity *parent = Q_NULLPTR);

    /**
     * @brief Returns the x coordinate of this Position.
     */
    int getX() const { return _x; }
    /**
     * @brief Returns the y coordinate of this Position.
     */
    int getY() const { return _y; }
    /**
     * @brief Returns the z coordinate of this Position.
     */
    int getZ() const { return _z; }

    /**
     * @brief Computes the distance between this Position and @c other.
     * @param other - the Position to compute the distance to.
     * @return the distance to the other Position, as a double.
     */
    double distance(Position* other) const;

    virtual uint hash(uint seed) const;
};

} // namespace component

#endif // COMPONENT_POSITION_H
