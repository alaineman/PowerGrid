#ifndef API_BRIDGE_ANIMABLE_H
#define API_BRIDGE_ANIMABLE_H

#include "MethodHelper.h"
#include "interactable.h"

namespace api {
namespace bridge {

/*!
 * \brief Represents movable objects in the Runescape world.
 *
 * All movable objects are instances of this class. This includes
 * NPCs and Players, but also projectiles and other miscellaneous
 * moving objects.
 *
 * This class provides a area in which the Animable can move through
 * \c getMinX, \c getMinY, \c getMaxX and \c getMaxY.
 * \internal Is this really the area of the Animable? I'm not sure...
 */
class Animable : public Interactable {
public:
    RS_OBJECT(Animable)

    /*!
     * \brief Returns the highest x-coordinate of this Animable's active area.
     * \return the highest x-coordinate of this Animable's active area.
     */
    JACE_PROXY_API JShort getMaxX();
    /*!
     * \brief Returns the highest y-coordinate of this Animable's active area.
     * \return the highest y-coordinate of this Animable's active area.
     */
    JACE_PROXY_API JShort getMaxY();
    /*!
     * \brief Returns the lowest x-coordinate of this Animable's active area.
     * \return the lowest x-coordinate of this Animable's active area.
     */
    JACE_PROXY_API JShort getMinX();
    /*!
     * \brief Returns the lowest y-coordinate of this Animable's active area.
     * \return the lowest y-coordinate of this Animable's active area.
     */
    JACE_PROXY_API JShort getMinY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMABLE_H
