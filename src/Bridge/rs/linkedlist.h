#ifndef API_BRIDGE_LINKEDLIST_H
#define API_BRIDGE_LINKEDLIST_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class LinkedListNode;

/*!
 * \brief Represents a LinkedList.
 *
 * It makes use of LinkedListNodes to form the actual list.
 * The LinkedListNodes should be cast to a specific subclass before
 * being used.
 * \see RS::LinkedListNode
 */
class LinkedList : public Object {
public:
    RS_OBJECT(LinkedList)

    /*!
     * \brief Returns the next LinkedListNode.
     * \return the next LinkedListNode
     * \internal the next node from what, exactly?
     */
    JACE_PROXY_API LinkedListNode getNext();
    /*!
     * \brief Returns the imaginary Node denoting the boundaries of the list
     * This LinkedListNode exists between the end and start nodes to mark the
     * beginning and end of the LinkedList.
     *
     * Beginning at this node and then repeatedly takeing the next node in a loop is
     * a convenient way to iterate over the LinkedList. When the next node at a given
     * moment is again equal to this node, the end of the LinkedList is reached.
     *
     * \return the sentinel node of this LinkedList
     */
    JACE_PROXY_API LinkedListNode getSentinel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_LINKEDLIST_H
