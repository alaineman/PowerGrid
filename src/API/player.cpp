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
#include "player.h"

#include "rs/client.h"
#include "rs/animator.h"
#include "rs/playerdef.h"

#include "java/lang/string.h"

namespace API {
namespace player {

RS::Player local() {
    return RS::Client::getLocalPlayer();
}

bool isIdle() {
    return local().getActiveAnimator().isNull();
}

Gender getGender() {
    return local().getPlayerDef().isFemale() ? Female : Male;
}

QString getName() {
    return local().getName().toQString();
}

int getLevel() {
    return local().getLevel().getInt();
}

int getX() {
    return local().getLocationX();
}

int getY() {
    return local().getLocationY();
}

} // namespace player
} // namespace API
