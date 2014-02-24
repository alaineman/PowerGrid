#ifndef API_BRIDGE_ENTITYNODE_H
#define API_BRIDGE_ENTITYNODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

/*!
 * \brief Represents any kind of entity
 * This behaves like a node in a linked list.
 * However, it has no relation to the \c LinkedListNode or \c Node classes.
 *
 * This class is different from the other node-based classes in that instances
 * of this class often directly refer to objects in the Runescape world.
 */
class EntityNode : public Object {
public:
    RS_OBJECT(EntityNode)

    /*!
     * \brief Returns the next EntityNode in the sequence
     * \return the next EntityNode
     */
    JACE_PROXY_API EntityNode getNext();
    /*!
     * \brief Returns the previous EntityNode in the sequence
     * \return the previous EntityNode
     */
    JACE_PROXY_API EntityNode getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ENTITYNODE_H
