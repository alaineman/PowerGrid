#ifndef API_BRIDGE_DEQUENODE_H
#define API_BRIDGE_DEQUENODE_H

#include "MethodHelper.h"
#include "node.h"

namespace api {
namespace bridge {

class Deque;

/*!
 * \brief Node subclass that references a Deque.
 */
class DequeNode : public Node {
public:
    RS_OBJECT(DequeNode)

    /*!
     * \brief Returns the Deque this Node refers to
     * \return this Node's Deque.
     */
    JACE_PROXY_API Deque getDeque();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_DEQUENODE_H
