#include "animableobject.h"
#include "objectdefloader.h"
#include "modelld.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimableObject, Animable)
IMPL_RSCLASS_GET(AnimableObject)

IMPL_PRIMITIVE_METHOD(AnimableObject, getID, JInt)
IMPL_OBJECT_METHOD(AnimableObject, getLDModel, ModelLD)
IMPL_PRIMITIVE_METHOD(AnimableObject, getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(AnimableObject, getLocationY, JInt)
IMPL_OBJECT_METHOD(AnimableObject, getObjectDefLoader, ObjectDefLoader)

} // namespace bridge
} // namespace api
