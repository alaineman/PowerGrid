#include "npcnode.h"
#include "npc.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(NPCNode, Node)
IMPL_RSCLASS_GET(NPCNode)

IMPL_OBJECT_METHOD(NPCNode, getNPC, NPC)

} // namespace bridge
