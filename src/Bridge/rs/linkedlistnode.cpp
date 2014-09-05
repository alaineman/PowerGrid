#include "linkedlistnode.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(LinkedListNode)
IMPL_RSCLASS_GET(LinkedListNode)

IMPL_OBJECT_METHOD(LinkedListNode, getNext, LinkedListNode)
IMPL_OBJECT_METHOD(LinkedListNode, getPrevious, LinkedListNode)

} // namespace bridge
