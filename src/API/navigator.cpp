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
#include "navigator.h"

#include "rs/client.h"
#include "rs/player.h"

#include "navigation.h"

namespace API {

using component::Position;

using RS::Client;
using RS::Player;

Navigator::Navigator() :
    _navigation(0) {
}

Position *Navigator::currentPosition() const {
    Player player = Client::getLocalPlayer();
    return new Position(player.getLocationX(),
                        player.getLocationY(),
                        player.getPlane().getByte());
}

Navigation* Navigator::findPath(Position* destination) {
    Position* current = currentPosition();
    Navigation* path = findPath(currentPosition(), destination);
    current->deleteLater();
    return path;
}

Navigation* Navigator::findPath(Position* origin, Position* destination) {
    Q_UNUSED(origin); // TODO implement path-finding algorithm
    return new Navigation(QList<Position*>() << destination);
}

void Navigator::move(Position* target) {
    // TODO implement move operation
    //      1. Translate target position to 2D based on camera coordinates
    //      2. Click the translated (2D) position
    Q_UNUSED(target)
}

void Navigator::navigate(Position* destination) {
    navigate(findPath(destination));
}

void Navigator::navigate(Navigation *navigation) {
    Q_ASSERT_X(navigation, "Navigator::navigate", "Navigation is NULL");
    _navigation = navigation;
    navigation->reset();
    emit started(navigation);
    move(navigation->next());
}

void Navigator::updateState() {
    // TODO if still busy, do nothing
    //      else:
    emit reached(_navigation->current());
    move(_navigation->next());
}

}
