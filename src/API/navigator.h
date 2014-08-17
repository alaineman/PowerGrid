#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QObject>
#include "entity/world.h"

#include "vec3d.h"

using entity::World;

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
    Vec3D currentPosition() const;

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
    Navigation* findPath(Vec3D destination);

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
    Navigation* findPath(Vec3D origin, Vec3D destination);

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
    void reached(Vec3D position);

public slots:
    /**
     * @brief Moves to the specified target
     *
     * If the target is too far away, this method makes no attempt to
     * compute intermediate targets, causing in undefined behavior.
     * As such, for arbitrary targets, please use the
     * @c navigate(Vec3D) function instead.
     *
     * @param target - the target to move towards
     */
    void move(Vec3D target);

    /**
     * @brief Navigates to the specified destination
     *
     * This function behaves effectively the same as calling
     * @c navigate(findPath(destination))
     *
     * @param destination - the destination to navigate towards
     */
    void navigate(Vec3D destination);

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
