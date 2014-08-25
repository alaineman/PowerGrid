#ifndef API_COMPONENT_POSITION_H
#define API_COMPONENT_POSITION_H

#include "entity/component.h"

using entity::HashableComponent;

namespace component {

/**
 * @brief Component for Entities with a position.
 *
 * This Component type represents a point in 3D space with
 * integer coordinates.
 */
class Position : public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(Position)
private:
    int _x, _y, _z;
public:
    /**
     * @brief Creates a new Position instance with the specified coordinates
     * @param x                 - the x coordinate
     * @param y                 - the y coordinate
     * @param z                 - the z coordinate
     * @param parent [optional] - the parent Entity
     */
    Position(int x, int y, int z, entity::Entity *parent = Q_NULLPTR);

    /**
     * @brief Returns the x coordinate of this Position.
     */
    int getX() const { return _x; }
    /**
     * @brief Returns the y coordinate of this Position.
     */
    int getY() const { return _y; }
    /**
     * @brief Returns the z coordinate of this Position.
     */
    int getZ() const { return _z; }

    /**
     * @brief Computes the distance between this Position and @c other.
     * @param other - the Position to compute the distance to.
     * @return the distance to the other Position, as a double.
     */
    double distance(Position* other) const;

    virtual uint hash(uint seed) const;
};

} // namespace component

#endif // API_COMPONENT_POSITION_H
