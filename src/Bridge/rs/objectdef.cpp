#include "objectdef.h"
#include "java/lang/string.h"
#include "objectdefloader.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ObjectDef)
IMPL_RSCLASS_GET(ObjectDef)

IMPL_ARRAY_METHOD(ObjectDef, getActions, String)
IMPL_PRIMITIVE_METHOD(ObjectDef, getID, JInt)
IMPL_ARRAY_METHOD(ObjectDef, getModifiedColors, JShort)
IMPL_OBJECT_METHOD(ObjectDef, getName, String)
IMPL_OBJECT_METHOD(ObjectDef, getObjectDefLoader, ObjectDefLoader)
IMPL_ARRAY_METHOD(ObjectDef, getOriginalColors, JShort)
IMPL_PRIMITIVE_METHOD(ObjectDef, isWalkable, JBoolean)

} // namespace bridge
