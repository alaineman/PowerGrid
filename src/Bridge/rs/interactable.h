#ifndef API_BRIDGE_INTERACTABLE_H
#define API_BRIDGE_INTERACTABLE_H

#include "MethodHelper.h"
#include "entitynode.h"


namespace RS {

/**
 * \brief Represents an interactable Entity in the Runescape world
 *
 * Interactable Entities are bound to a certain plane, and sometimes
 * allow some sort of interaction with the Entity.
 */
class Interactable : public EntityNode {
public:
    RS_OBJECT(Interactable)

    /**
     * \brief Returns the plane on which this entity resides.
     */
    JACE_PROXY_API JByte getPlane();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_INTERACTABLE_H
