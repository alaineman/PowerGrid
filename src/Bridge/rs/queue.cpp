#include "queue.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Queue)
IMPL_RSCLASS_GET(Queue)

IMPL_OBJECT_METHOD(Queue, getCurrent, NodeSub)
IMPL_OBJECT_METHOD(Queue, getSentinel, NodeSub)

} // namespace bridge

