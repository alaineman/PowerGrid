#include "wallobject.h"
#include "modelld.h"
#include "objectdefloader.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(WallObject, WallDecoration)
IMPL_RSCLASS_GET(WallObject)

IMPL_PRIMITIVE_METHOD(WallObject, getID, JInt)
IMPL_OBJECT_METHOD(WallObject, getLDModel, ModelLD)
IMPL_PRIMITIVE_METHOD(WallObject, getLocalX, JDouble)
IMPL_PRIMITIVE_METHOD(WallObject, getLocalY, JDouble)
IMPL_PRIMITIVE_METHOD(WallObject,getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(WallObject,getLocationY, JInt)
IMPL_OBJECT_METHOD(WallObject, getObjectDefLoader, ObjectDefLoader)

} // namespace bridge
} // namespace api
