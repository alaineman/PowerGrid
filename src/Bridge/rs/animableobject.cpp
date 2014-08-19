#include "animableobject.h"
#include "objectdefloader.h"
#include "modelld.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimableObject, Animable)
IMPL_RSCLASS_GET(AnimableObject)

IMPL_PRIMITIVE_METHOD(AnimableObject, getID, JInt)
IMPL_OBJECT_METHOD(AnimableObject, getModel, ModelLD)
IMPL_PRIMITIVE_METHOD(AnimableObject, getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(AnimableObject, getLocationY, JInt)
IMPL_OBJECT_METHOD(AnimableObject, getObjectDefLoader, ObjectDefLoader)

} // namespace bridge
