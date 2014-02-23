#include "linkedlistnode.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(LinkedListNode)
IMPL_RSCLASS_GET(LinkedListNode)

IMPL_OBJECT_METHOD(LinkedListNode, getNext, LinkedListNode)
IMPL_OBJECT_METHOD(LinkedListNode, getPrevious, LinkedListNode)

} // namespace bridge
} // namespace api
