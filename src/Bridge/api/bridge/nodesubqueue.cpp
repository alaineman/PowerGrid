#include "nodesubqueue.h"
#include "nodesub.h"
namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(NodeSubQueue)
IMPL_RSCLASS_GET(NodeSubQueue)

IMPL_OBJECT_METHOD(NodeSubQueue, getTail, NodeSub)

} // namespace bridge
} // namespace api
