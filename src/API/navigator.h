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

using entity::World;
using component::Position;

class Navigation;

/**
 * @brief Utility class responsible for movement across the World
 *
 * This class provides functions to move across the RS world. It makes
 * use of Navigation instances to represent paths it follows.
 *
 * The state of the Navigator can be asynchronously monitored by
 * connecting to one of its signals.
 *
 */
class Navigator : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Navigator)
private:
    Navigation* _navigation;
public:
    /**
     * @brief Creates a new Navigator instance.
     */
    Navigator();

    /**
     * @brief Returns the current position of the player.
     * @return the current position of the player
     */
    Position* currentPosition() const;

    /**
     * @brief Returns the current Navigation path
     * @return the current Navigation, or NULL if no Navigation is currently active.
     */
    Navigation* currentPath() const { return _navigation; }

    /**
     * @brief Computes and returns a path to the destination
     *
     * This function computes the (almost) shortest path between
     * @c origin and @c destination. In computing the path, this
     * function may deliberately choose to insert small detours,
     * or make small mistakes. This behavior causes paths computed
     * with this function to appear more human-like.
     *
     * The starting point of the Navigation path is taken to
     * be the current position, as given by @c currentPosition().
     *
     * This function is effectively the same as calling
     * @c findPath(currentPosition(), destination)
     *
     * @param destination - the destination of the Navigation path
     * @return the computed path
     */
    Navigation* findPath(Position* destination);

    /**
     * @brief Computes and returns a path to the destination
     *
     * This function computes the (almost) shortest path between
     * @c origin and @c destination. In computing the path, this
     * function may deliberately choose to insert small detours,
     * or make small mistakes. This behavior causes paths computed
     * with this function to appear more human-like.
     *
     * @param origin      - the starting point of the Navigation path
     * @param destination - the destination of the Navigation path
     * @return the computed path
     */
    Navigation* findPath(Position* origin, Position* destination);

signals:
    /**
     * @brief Signal emitted whenever a Navigation is started
     */
    void started(Navigation*);
    /**
     * @brief Signal emitted whenever a Navigation is finished
     */
    void finished(Navigation*);
    /**
     * @brief Signal emitted periodically to indicate progress
     *
     * @param position - the position that was reached
     */
    void reached(Position* position);

public slots:
    /**
     * @brief Moves to the specified target
     *
     * If the target is too far away, this method makes no attempt to
     * compute intermediate targets, causing in undefined behavior.
     * As such, for arbitrary targets, please use the
     * @c navigate(Position*) function instead.
     *
     * @param target - the target to move towards
     */
    void move(Position* target);

    /**
     * @brief Navigates to the specified destination
     *
     * This function behaves effectively the same as calling
     * @c navigate(findPath(destination))
     *
     * @param destination - the destination to navigate towards
     */
    void navigate(Position* destination);

    /**
     * @brief Navigates along the given path
     *
     * If the first position of the Navigation path is out of range,
     * the behavior of this function is undefined. Otherwise, this function
     * starts navigating along the given path.
     *
     * @param navigation - the Navigation path to follow.
     */
    void navigate(Navigation* navigation);

    /**
     * @brief Updates the state of the Navigator
     *
     * This function should be called periodically to advance to the next
     * point along the Navigation.
     *
     * This function is (under normal circumstances) automatically
     * called periodically, so there is usually no need to call this
     * manually.
     */
    void updateState();
};

#endif // NAVIGATOR_H
