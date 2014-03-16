#include "dequenode.h"
#include "deque.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(DequeNode, Node)
IMPL_RSCLASS_GET(DequeNode)

IMPL_OBJECT_METHOD(DequeNode, getDeque, Deque)

} // namespace bridge
} // namespace api
