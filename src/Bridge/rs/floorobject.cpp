#include "floorobject.h"
#include "modelld.h"
#include "objectdefloader.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(FloorObject, FloorDecoration)
IMPL_RSCLASS_GET(FloorObject)

IMPL_PRIMITIVE_METHOD(FloorObject, getID, JInt)
IMPL_OBJECT_METHOD(FloorObject, getModel, ModelLD)
IMPL_PRIMITIVE_METHOD(FloorObject, getLocalX, JDouble)
IMPL_PRIMITIVE_METHOD(FloorObject, getLocalY, JDouble)
IMPL_PRIMITIVE_METHOD(FloorObject,getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(FloorObject,getLocationY, JInt)
IMPL_OBJECT_METHOD(FloorObject, getObjectDefLoader, ObjectDefLoader)


} // namespace bridge
