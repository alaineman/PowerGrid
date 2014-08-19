#ifndef API_BRIDGE_GROUNDENTITY_H
#define API_BRIDGE_GROUNDENTITY_H

#include "MethodHelper.h"
#include "interactable.h"


namespace RS {

/*!
 * \brief The GroundEntity class
 *
 * All non-movable  interactable objects and items bound the Runescape World ground.
 *
 * \internal confirm non-movable
 * \internal confirm bound to Tile
 * \internal missing tons of methods in GroundEntity and it's subclasses
 */
class GroundEntity : public Interactable {
public:
    RS_OBJECT(GroundEntity)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_GROUNDENTITY_H
