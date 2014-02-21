#include "node.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Node)
IMPL_RSCLASS_GET(Node)

IMPL_PRIMITIVE_METHOD(Node, getID, JLong)
IMPL_OBJECT_METHOD(Node, getNext, Node)
IMPL_OBJECT_METHOD(Node, getPrevious, Node)

} // namespace bridge
} // namespace api
