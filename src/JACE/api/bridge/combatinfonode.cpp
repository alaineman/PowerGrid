#include "combatinfonode.h"
#include "linkedlist.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(CombatInfoNode, LinkedListNode)
IMPL_RSCLASS_GET(CombatInfoNode)

IMPL_OBJECT_METHOD(CombatInfoNode, getData, LinkedList)

} // namespace bridge
} // namespace api
