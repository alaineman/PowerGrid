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
#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QObject>

#include "entity/world.h"
#include "component/position.h"

#include "Dstar.h"

namespace API {

using component::Position;
using entity::World;

/**
 * @brief Mode to use for the Navigator.
 *
 * This enum specifies different ways in which the Navigator can
 * navigate to the destination.
 *
 * While OnTile is most precise, the other values allow for
 * more variance in the path that is followed, giving a more human-like impression.
 * Also note that the OnTile mode may fail if the target tile is not walkable
 * (for obvious reasons).
 *
 * The default mode is OnWindow, which stops if the target is visible in the game
 * window (which is usually what you want anyway).
 */
enum NavigationMode {
    OnMinimap, ///< Indicates the target should be visible on the minimap.
    OnWindow,  ///< Indicates the target should be visible in the window.
    OnTile     ///< Indicates the player should end up on the target tile.
};

/**
 * @brief Utility class responsible for movement across the World
 *
 * This class provides functions to move across the RS world. It uses the
 * data from the RS client to try and find a shortest path across the world.
 *
 * The Navigator class makes use of a D* Lite algorithm to determine its paths.
 * This allows navigation across the entire world, even though not all world data
 * may be available all the time. If there exists no path, the Navigator may try
 * to navigate towards the goal, possibly using large detours, and may never report
 * a failure (and may take a long time trying to find valid paths). However, seeing
 * as how almost every location in the Runescape world is reachable, this should not
 * cause major problems in practise.
 *
 * The algorithm will always work on a best-effort basis: If a path possibly exists,
 * it tries to navigate along the shortest path (even if some of the world data is
 * missing). If, at a certain point in time, the path turns out to be invalid, the
 * algorithm changes the path automatically to include the new knowledge.
 *
 * Instances of this class are not thread-safe, and not re-entrant. Navigator
 * instances are intended to be used within a single component only, and should
 * not be shared to prevent the Navigator from entering an inconsistent state.
 *
 * Navigator instances are single-use objects. If they are used once, they cannot be
 * used again (even when the previous operation failed or was cancelled). Trying to use
 * a Navigator that has already been used causes an exception to be raised.
 */
class Navigator : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Navigator)
private:
    /// Enum specifying the internal state of the Navigator.
    enum State {
        NotStarted, InProgress, Finished
    };

    Dstar* dstar;           ///< The Dstar instance doing the algorithm
    State navState;         ///< The internal state of this Navigator
    NavigationMode navMode; ///< The Navigation Mode
    int curX, curY;         ///< The current target (x,y)
    int targetX, targetY;   ///< The final target (x,y)

    /**
     * @brief Loads the world data into the DStar instance.
     */
    void loadWorldData();

    /**
     * @brief Marks this Navigator as done.
     */
    void finishUp();

    /**
     * @brief Checks if the goal has been reached.
     *
     * @return true if the finish was reached, false otherwise
     */
    bool checkFinish();

    /**
     * @brief Moves to the specified target.
     *
     * It may be possible the target tile is never reached,
     * but this function makes best attempt to target the
     * specified coordinates. Especially when the target is
     * beyond the reach of the player, this function only moves
     * in the direction of the target, but the actual distance
     * travelled is undefined.
     *
     * @param x - the x coordinate of the target
     * @param y - the y coordinate of the target
     */
    void move(int x, int y);
public:
    /**
     * @brief Creates a new Navigator instance.
     */
    Navigator();
    virtual ~Navigator();

signals:
    /**
     * @brief Signal emitted whenever a Navigation is started
     */
    void started(Position* origin, Position* destination);
    /**
     * @brief Signal emitted whenever a Navigation is finished
     */
    void finished(Position* origin, Position* destination);
    /**
     * @brief Signal emitted periodically to indicate progress
     *
     * @param position - the position that was reached
     */
    void reached(Position* position);

    /**
     * @brief Signal emitted when the Navigation could not be completed.
     *
     * @param message - the reason for the failure.
     */
    void errorOccurred(QString message);

public slots:

    /**
     * @brief Executes a step in the Navigation path.
     *
     * This function recomputes the path as required and moves to the
     * next position.
     */
    void step();

    /**
     * @brief Navigates to the specified destination
     *
     * @param destination - the destination to navigate towards
     */
    void navigate(Position* destination, NavigationMode mode = OnWindow);
};

}

#endif // NAVIGATOR_H
