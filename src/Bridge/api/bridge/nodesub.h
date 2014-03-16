#ifndef API_BRIDGE_NODESUB_H
#define API_BRIDGE_NODESUB_H

#include "MethodHelper.h"
#include "node.h"

namespace api {
namespace bridge {

/**
 * @brief Node element representing a LinkedList
 *
 * This Node represents a separate LinkedList (of NodeSubs) as element in a
 * LinkedList (of Nodes). It is usually used in cases where the elements
 * of a LinkedList are actually LinkedLists by themselves.
 */
class NodeSub : public Node {
public:
    RS_OBJECT(NodeSub)

    JACE_PROXY_API JInt getIDSub();
    JACE_PROXY_API NodeSub getNextSub();
    JACE_PROXY_API NodeSub getPreviousSub();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NODESUB_H
