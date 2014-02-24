#ifndef API_BRIDGE_NODE_H
#define API_BRIDGE_NODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

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
     * \return the next Node.
     * \internal does this return \c NULL or \c *this when the end of the list is reached?
     */
    JACE_PROXY_API Node getNext();
    /*!
     * \brief Returns the previous Node in the sequence
     * \return the previous Node.
     * \internal does this return \c NULL or \c *this when the beginning of the list is reached?
     */
    JACE_PROXY_API Node getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NODE_H
