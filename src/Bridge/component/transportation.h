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
#ifndef COMPONENT_TRANSPORTATION_H
#define COMPONENT_TRANSPORTATION_H

#include "entity/component.h"

using entity::HashableComponent;

namespace component {

class Position;
class Action;


class Transportation : public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(Transportation)
private:
    Position* from;
    Position* to;
    int cost;
    Action* action;
public:
    Transportation(Position* _from, Position* _to, int _cost, Action* _action, entity::Entity *parent = 0);

    Position* getFrom() const;
    Position* getTo() const;
    int getCost() const;
    Action* getAction() const;

    virtual uint hash(uint seed) const;
};

} // namespace component

#endif // COMPONENT_TRANSPORTATION_H
