#include "deque.h"

#include "node.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Deque)
IMPL_RSCLASS_GET(Deque)

IMPL_OBJECT_METHOD(Deque, getCurrent, Node)
IMPL_OBJECT_METHOD(Deque, getSentinel, Node)

} // namespace bridge
