#include "itemdef.h"
#include "hashtable.h"
#include "itemdefloader.h"
#include "java/lang/string.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(ItemDef)
IMPL_RSCLASS_GET(ItemDef)

IMPL_ARRAY_METHOD(ItemDef, getActions, String)
IMPL_ARRAY_METHOD(ItemDef, getGroundActions, String)
IMPL_PRIMITIVE_METHOD(ItemDef, getID, JInt)
IMPL_OBJECT_METHOD(ItemDef, getItemDefLoader, ItemDefLoader)
IMPL_OBJECT_METHOD(ItemDef, getName, String)
IMPL_OBJECT_METHOD(ItemDef, getNodeTable, HashTable)



} // namespace bridge
} // namespace api
