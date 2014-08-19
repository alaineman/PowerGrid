#include "nodesub.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(NodeSub, Node)
IMPL_RSCLASS_GET(NodeSub)

IMPL_PRIMITIVE_METHOD(NodeSub, getIDSub, JInt)
IMPL_OBJECT_METHOD(NodeSub, getNextSub, NodeSub)
IMPL_OBJECT_METHOD(NodeSub, getPreviousSub, NodeSub)

} // namespace bridge
