#include "nodesub.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(NodeSub, Node)
IMPL_RSCLASS_GET(NodeSub)

IMPL_PRIMITIVE_METHOD(NodeSub, getIDSub, JInt)
IMPL_OBJECT_METHOD(NodeSub, getNextSub, NodeSub)
IMPL_OBJECT_METHOD(NodeSub, getNextSub, NodeSub)

} // namespace bridge
} // namespace api
