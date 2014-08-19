#include "linkedlist.h"
#include "linkedlistnode.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(LinkedList)
IMPL_RSCLASS_GET(LinkedList)

IMPL_OBJECT_METHOD(LinkedList, getNext, LinkedListNode)
IMPL_OBJECT_METHOD(LinkedList, getSentinel, LinkedListNode)

} // namespace bridge
