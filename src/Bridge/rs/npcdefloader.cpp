#include "npcdefloader.h"
#include "cache.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(NPCDefLoader)
IMPL_RSCLASS_GET(NPCDefLoader)

IMPL_OBJECT_METHOD(NPCDefLoader, getDefCache, Cache)
IMPL_OBJECT_METHOD(NPCDefLoader, getDialogModelCache, Cache)
IMPL_OBJECT_METHOD(NPCDefLoader, getModelCache, Cache)

} // namespace bridge
