#ifndef API_BRIDGE_NODESUBQUEUE_H
#define API_BRIDGE_NODESUBQUEUE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class NodeSub;
class NodeSubQueue : public Object {
public:
    RS_OBJECT(NodeSubQueue)

    JACE_PROXY_API NodeSub getTail();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NODESUBQUEUE_H
