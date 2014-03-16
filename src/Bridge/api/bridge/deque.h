#ifndef API_BRIDGE_DEQUE_H
#define API_BRIDGE_DEQUE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Node;

/*!
 * \brief Node-based Deque implementation
 *
 * Like other Node-based classes, this Deque is implemented using a LinkedList.
 */
class Deque : public Object {
public:
    RS_OBJECT(Deque)

    /*!
     * \brief Returns the currently active Node.
     *
     * This method simply returns the active Node according to the Runescape client.
     * To iterate over the Deque in order, start from the sentinel Node.
     * \return the currently active Node
     */
    JACE_PROXY_API Node getCurrent();
    /*!
     * \brief The sentinel node of this Deque
     *
     * This Node is an imaginary Node marking the boundaries of the Deque.
     */
    JACE_PROXY_API Node getSentinel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_DEQUE_H
