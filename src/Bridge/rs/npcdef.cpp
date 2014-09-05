#include "npcdef.h"
#include "hashtable.h"
#include "npcdefloader.h"
#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(NPCDef)
IMPL_RSCLASS_GET(NPCDef)

IMPL_ARRAY_METHOD(NPCDef, getActions, String)
IMPL_OBJECT_METHOD(NPCDef, getChildrenIDs, Object)
IMPL_PRIMITIVE_METHOD(NPCDef, isClickable, JBoolean)
IMPL_OBJECT_METHOD(NPCDef, getDialogModels, Object)
IMPL_PRIMITIVE_METHOD(NPCDef, getID, JInt)
IMPL_PRIMITIVE_METHOD(NPCDef, getLevel, JInt)
IMPL_PRIMITIVE_METHOD(NPCDef, getModelBoundRadius, JInt)
IMPL_ARRAY_METHOD(NPCDef, getModifiedColors, JShort)
IMPL_OBJECT_METHOD(NPCDef, getName, String)
IMPL_OBJECT_METHOD(NPCDef, getNPCDefLoader, NPCDefLoader)
IMPL_OBJECT_METHOD(NPCDef, getNodeTable, HashTable)
IMPL_PRIMITIVE_METHOD(NPCDef, getPrayerHeadIconIndex, JInt)
IMPL_PRIMITIVE_METHOD(NPCDef, getRenderEmote, JInt)
IMPL_PRIMITIVE_METHOD(NPCDef, isVisibleOnMinimap, JBoolean)

} // namespace bridge
