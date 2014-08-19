#include "menugroupnode.h"
#include "java/lang/string.h"
#include "nodesubqueue.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(MenuGroupNode, NodeSub)
IMPL_RSCLASS_GET(MenuGroupNode)

IMPL_OBJECT_METHOD(MenuGroupNode, getItems, NodeSubQueue)
IMPL_OBJECT_METHOD(MenuGroupNode, getOption, String)
IMPL_PRIMITIVE_METHOD(MenuGroupNode, getSize, JInt)

} // namespace bridge
