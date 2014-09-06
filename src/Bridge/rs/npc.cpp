#include "npc.h"
#include "npcdef.h"
#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(NPC, Character)
IMPL_RSCLASS_GET(NPC)

IMPL_PRIMITIVE_METHOD(NPC, getID, JInt)
IMPL_PRIMITIVE_METHOD(NPC, getLevel, JInt)
IMPL_OBJECT_METHOD(NPC, getNPCDef, NPCDef)
IMPL_OBJECT_METHOD(NPC, getName, String)

} // namespace bridge
