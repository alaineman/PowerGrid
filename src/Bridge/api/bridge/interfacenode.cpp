#include "interfacenode.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(InterfaceNode, Node)
IMPL_RSCLASS_GET(InterfaceNode)

IMPL_PRIMITIVE_METHOD(InterfaceNode, getMainID, JInt)

} // namespace bridge
} // namespace api
