#ifndef API_BRIDGE_NODESUB_H
#define API_BRIDGE_NODESUB_H

#include "MethodHelper.h"
#include "node.h"

namespace api {
namespace bridge {

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
