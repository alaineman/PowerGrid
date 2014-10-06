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
#include "player.h"
#include "Dstar.h"

// The maximum amount of noise to insert for the various navigation modes.
// The minimap shows 14 tiles in each direction, and the window approximately
// 3. When the mode is set to OnWindow, the camera needs to be checked as well
// to prevent cases where the camera angle is set in such a way, that the tile
// is not visible even though we're within 3 tiles.
#define NAV_NOISE_MINIMAP 14
#define NAV_NOISE_WINDOW  3

// The minimal distance the player should be to the target before the algorithm
// considers the player close enough to move to the next spot. The number represents
// the amount of tiles.
#define NAV_DIST_THRESHOLD 3

namespace API {

using component::Position;

Navigator::Navigator() :
    dstar(new Dstar()),
    navState(NotStarted) {
}
Navigator::~Navigator() {
    if (dstar) {
        delete dstar;
    }
}

void Navigator::loadWorldData() {
    if (navState != InProgress) {
        throw logic_error("Invalid state: loadWorldData() called without active navigation");
    }
    // TODO update the World state.
}

void Navigator::move(int x, int y) {
    if (navState != InProgress) {
        throw logic_error("Invalid state: move(int,int) called without active navigation");
    }
    // TODO implement move operation as follows:
    //   a. If the position is visible on the window:
    //      1. Translate target position to 2D based on camera coordinates
    //      2. Click the translated (2D) position
    //   b. Else, if the position is visible on the minimap:
    //      1. Determine the location of the target on the minimap using the camera rotation.
    //      2. Click the location on the minimap.
    //   c. Else:
    //      1. Find a position (a,b) less than NAV_NOISE_MINIMAP*2/3 away in the same direction as (x,y)
    //      2. call move(a,b) // This ensures either the a. or b. branch fires.
    Q_UNUSED(x);
    Q_UNUSED(y);
}

void Navigator::step() {
    if (navState != InProgress) {
        throw logic_error("Invalid state: step() called without active navigation");
    }

    int playerX = API::player::getX();
    int playerY = API::player::getY();
    int dx = playerX - curX;
    int dy = playerY - curY;
    int dist = dx*dx + dy*dy;
    if (dist > NAV_DIST_THRESHOLD*NAV_DIST_THRESHOLD) {
        // We're still too far away, so we don't continue
        return;
    }

    loadWorldData();
    dstar->updateStart(playerX, playerY);
    dstar->replan();
    std::list<state> path = dstar->getPath().path;

    if (path.empty()) {
        finishUp();
    } else {
        state nextState = path.front();
        move(nextState.x, nextState.y);
        if (checkFinish()) {
            finishUp();
        }
    }
}

bool Navigator::checkFinish() {
    int playerX = API::player::getX();
    int playerY = API::player::getY();
    int dx = playerX - targetX;
    int dy = playerY - targetY;

    switch (navMode) {
    case OnTile:
        return dx == 0 && dy == 0;
    case OnWindow:
        return dx*dx - dy*dy <= NAV_NOISE_WINDOW*NAV_NOISE_WINDOW;
    case OnMinimap:
        return dx*dx - dy*dy <= NAV_NOISE_MINIMAP*NAV_NOISE_MINIMAP;
    default:
        // should not happen, but some compilers warn about missing a return value here.
        throw std::logic_error("Invalid NavigationMode");
    }
}

void Navigator::finishUp() {
    navState = Finished;

    World* world = World::instance();
    disconnect(world, SIGNAL(processingFinished()),
               this,  SLOT(step()));

    // We might as well free the memory used by Dstar right away
    if (dstar) delete dstar;
    dstar = NULL;
}

void Navigator::navigate(Position* destination, NavigationMode mode) {
    Q_ASSERT(destination != NULL);
    if (navState != NotStarted) {
        throw std::logic_error("Invalid state: This Navigator has already been started");
    }
    navState = InProgress;
    navMode  = mode;
    targetX  = destination->getX();
    targetY  = destination->getY();

    int playerX = API::player::getX();
    int playerY = API::player::getY();
    dstar->init(playerX, playerY, targetX, targetY);
    loadWorldData();

    World* world = World::instance();
    connect( world, SIGNAL(processingFinished()),
             this,  SLOT(step()));

}

}
