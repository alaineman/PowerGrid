#include "nodesubqueue.h"
#include "nodesub.h"

namespace RS {

IMPL_JACE_CONSTRUCTORS(NodeSubQueue)
IMPL_RSCLASS_GET(NodeSubQueue)

IMPL_OBJECT_METHOD(NodeSubQueue, getTail, NodeSub)

} // namespace bridge
