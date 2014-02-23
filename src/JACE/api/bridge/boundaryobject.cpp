#include "boundaryobject.h"

#include "modelld.h"
#include "objectdefloader.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(BoundaryObject, Boundary)
IMPL_RSCLASS_GET(BoundaryObject)

IMPL_PRIMITIVE_METHOD(BoundaryObject, getID, JInt)
IMPL_OBJECT_METHOD(BoundaryObject, getLDModel, ModelLD)
IMPL_PRIMITIVE_METHOD(BoundaryObject, getLocalX, JDouble)
IMPL_PRIMITIVE_METHOD(BoundaryObject, getLocalY, JDouble)
IMPL_PRIMITIVE_METHOD(BoundaryObject, getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(BoundaryObject, getLocationY, JInt)
IMPL_OBJECT_METHOD(BoundaryObject, getObjectDefLoader, ObjectDefLoader)


} // namespace bridge
} // namespace api
