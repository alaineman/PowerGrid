#ifndef API_BRIDGE_DEQUENODE_H
#define API_BRIDGE_DEQUENODE_H

#include "MethodHelper.h"
#include "node.h"

namespace api {
namespace bridge {

class Deque;

class DequeNode : public Node {
public:
    RS_OBJECT(DequeNode)

    JACE_PROXY_API Deque getDeque();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_DEQUENODE_H
