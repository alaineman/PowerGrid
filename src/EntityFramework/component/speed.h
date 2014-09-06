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
#ifndef COMPONENT_SPEED_H
#define COMPONENT_SPEED_H

#include "entity/component.h"

using entity::Component;

namespace component {

class Speed : public Component {
    Q_OBJECT
    Q_DISABLE_COPY(Speed)
private:
    double value;
public:
    explicit Speed(double speed, entity::Entity *parent = 0);
    double getCurrentSpeed() const { return value; }
};

} // namespace component

#endif // COMPONENT_SPEED_H
