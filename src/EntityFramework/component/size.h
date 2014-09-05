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
#ifndef COMPONENT_SIZE_H
#define COMPONENT_SIZE_H

#include "entity/component.h"

using entity::HashableComponent;

namespace component {

class Size : public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(Size)
private:
    int _x, _y;
public:
    Size(int x, int y, entity::Entity *parent = Q_NULLPTR);
    int getWidth() const { return _x; }
    int getHeight() const { return _y; }

    virtual uint hash(uint seed) const;
};

} // namespace component

#endif // COMPONENT_SIZE_H
