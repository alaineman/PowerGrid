#ifndef API_BRIDGE_NODE_H
#define API_BRIDGE_NODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

/*!
 * \brief General-purpose LinkedList-style Node.
 *
 * A Node instance is usually part of a chain of similar Node instance,
 * accessible by \c getNext() and \c getPrevious().
 *
 * Unlike other Node-like classes, instances of this class often represent raw data
 * that resembles objects in the Runescape world.
 */
class Node : public Object {
public:
    RS_OBJECT(Node)

    /*!
     * \brief Returns a (pseudo-)unique number for this Node.
     * \return the id of this Node
     */
    JACE_PROXY_API JLong getID();
    /*!
     * \brief Returns the next Node in the sequence
     *
     * If the end of the sequence is reached, this returns the sentinel
     * Node of the structure it belongs to.
     * \internal ^ That's how it works, right?
     * \return the next Node.
     */
    JACE_PROXY_API Node getNext();
    /*!
     * \brief Returns the previous Node in the sequence
     *
     * If the beginning of the sequence is reached, this returns the sentinel
     * Node of the structure it belongs to.
     * \internal ^ That's how it works, right?
     * \return the previous Node.
     */
    JACE_PROXY_API Node getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_NODE_H
