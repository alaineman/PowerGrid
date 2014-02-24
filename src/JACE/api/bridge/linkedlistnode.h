#ifndef API_BRIDGE_LINKEDLISTNODE_H
#define API_BRIDGE_LINKEDLISTNODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

/*!
 * \brief Node in a LinkedList.
 *
 * Instances of this class by themselves do not contain any data.
 * Therefore, instances of this class are only useful when cast to
 * a subclass.
 */
class LinkedListNode : public Object {
public:
    RS_OBJECT(LinkedListNode)

    /*!
     * \brief Returns the next LinkedListNode.
     * \return the next LinkedListNode
     */
    JACE_PROXY_API LinkedListNode getNext();
    /*!
     * \brief Returns the previous LinkedListNode.
     * \return the previous LinkedListNode
     */
    JACE_PROXY_API LinkedListNode getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_LINKEDLISTNODE_H
