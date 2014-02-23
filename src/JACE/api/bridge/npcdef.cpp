#include "npcdef.h"
#include "hashtable.h"
#include "java/lang/string.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(NPCDef)
IMPL_RSCLASS_GET(NPCDef)

IMPL_ARRAY_METHOD(NPCDef, getActions, String)
IMPL_PRIMITIVE_METHOD(NPCDef, getID, JInt)
IMPL_PRIMITIVE_METHOD(NPCDef, getModelBoundRadius, JInt)
IMPL_OBJECT_METHOD(NPCDef, getName, String)
IMPL_OBJECT_METHOD(NPCDef, getNodeTable, HashTable)
IMPL_PRIMITIVE_METHOD(NPCDef, getPrayerHeadIconIndex, JInt)
IMPL_PRIMITIVE_METHOD(NPCDef, getRenderEmote, JInt)

} // namespace bridge
} // namespace api
