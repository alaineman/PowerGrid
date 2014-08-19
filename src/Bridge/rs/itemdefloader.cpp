#include "itemdefloader.h"
#include "cache.h"
#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ItemDefLoader)
IMPL_RSCLASS_GET(ItemDefLoader)

IMPL_ARRAY_METHOD(ItemDefLoader, getDefaultActions, String)
IMPL_ARRAY_METHOD(ItemDefLoader, getDefaultGroundActions, String)
IMPL_PRIMITIVE_METHOD(ItemDefLoader, getItemCount, JInt)
IMPL_OBJECT_METHOD(ItemDefLoader, getItemDefCache, Cache)
IMPL_OBJECT_METHOD(ItemDefLoader, getItemModelCache, Cache)
IMPL_PRIMITIVE_METHOD(ItemDefLoader, getLanguage, JInt)
IMPL_PRIMITIVE_METHOD(ItemDefLoader, isMembers, JBoolean)

} // namespace bridge
