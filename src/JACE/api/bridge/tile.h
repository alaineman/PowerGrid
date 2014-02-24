#ifndef API_BRIDGE_TILE_H
#define API_BRIDGE_TILE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AnimableNode;
class Boundary;
class FloorDecoration;
class GroundEntity;
class WallDecoration;

/*!
 * \brief Represents a Tile in the Runescape world.
 * The Tile class contains fields to represent the objects on a single
 * tile in the Runescape world.
 *
 * Any of the object fields in this class may contain a \c NULL value if
 * there is no object in that particular position.
 */
class Tile : public Object {
public:
    RS_OBJECT(Tile)

    JACE_PROXY_API AnimableNode getAnimableList(); // What exactly does this represent?
    /*!
     * \brief Returns the first Boundary object on this Tile.
     * \return the first Boundary object, or \c NULL if no Boundary exists on this Tile.
     */
    JACE_PROXY_API Boundary getBoundary1();
    /*!
     * \brief Returns the second Boundary object on this Tile.
     * \return the second Boundary object, or \c NULL if no Boundary exists on this Tile.
     */
    JACE_PROXY_API Boundary getBoundary2();    
    /*!
     * \brief Returns the FloorDecoration object on this Tile.
     * \return the FloorDecoration object, or \c NULL if no FloorDecoration exists on this Tile.
     */
    JACE_PROXY_API FloorDecoration getFloorDecoration();
    /*!
     * \brief Returns the GroundEntity object on this Tile.
     * \return the GroundEntity object, or \c NULL if no GroundEntity exists on this Tile.
     */
    JACE_PROXY_API GroundEntity getGroundEntity();
    /*!
     * \brief Returns the plane on which this Tile resides.
     * \return the plane on which this Tile resides, as a byte.
     */
    JACE_PROXY_API JByte getPlane();
    /*!
     * \brief Returns the first WallDecoration object on this Tile.
     * \return the first WallDecoration object, or \c NULL if no WallDecoration exists on this Tile.
     */
    JACE_PROXY_API WallDecoration getWallDecoration1();
    /*!
     * \brief Returns the second WallDecoration object on this Tile.
     * \return the second WallDecoration object, or \c NULL if no WallDecoration exists on this Tile.
     */
    JACE_PROXY_API WallDecoration getWallDecoration2();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_TILE_H
