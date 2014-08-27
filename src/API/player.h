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
#ifndef API_PLAYER_H
#define API_PLAYER_H

#include "rs/player.h"

namespace API {

/**
 * @namespace API::player
 * @brief utility namespace for the local player
 *
 * This namespace contains functions that provide information
 * about the local player.
 */
namespace player {

/**
 * @brief Enum specifying a gender
 */
enum Gender {
    Male   = 0, ///< Indicates a Male player
    Female = 1  ///< Indicates a Female player
};

/**
 * @brief Returns the local player
 * @return the local player
 */
RS::Player local();

/**
 * @brief Returns whether the local player is idle.
 *
 * The player is considered idle when there is no active animation.
 * @return true if the player is idle, false otherwise.
 */
bool isIdle();

/**
 * @brief Returns the Gender of the local player
 */
Gender getGender();

/**
 * @brief Returns the name of the local player
 */
QString getName();

/**
 * @brief Return the level of the local player
 */
int getLevel();

} // namespace player
} // namespace API

#endif // API_PLAYER_H
