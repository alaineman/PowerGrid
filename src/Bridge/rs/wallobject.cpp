#include "wallobject.h"
#include "modelld.h"
#include "objectdefloader.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(WallObject, WallDecoration)
IMPL_RSCLASS_GET(WallObject)

IMPL_PRIMITIVE_METHOD(WallObject, getID, JInt)
IMPL_OBJECT_METHOD(WallObject, getModel, ModelLD)
IMPL_PRIMITIVE_METHOD(WallObject, getLocalX, JDouble)
IMPL_PRIMITIVE_METHOD(WallObject, getLocalY, JDouble)
IMPL_PRIMITIVE_METHOD(WallObject,getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(WallObject,getLocationY, JInt)
IMPL_OBJECT_METHOD(WallObject, getObjectDefLoader, ObjectDefLoader)

} // namespace bridge

