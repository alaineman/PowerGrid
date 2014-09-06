#include "menuitemnode.h"
#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(MenuItemNode, NodeSub)
IMPL_RSCLASS_GET(MenuItemNode)

IMPL_OBJECT_METHOD(MenuItemNode, getAction, String)
IMPL_OBJECT_METHOD(MenuItemNode, getOption, String)

} // namespace bridge
