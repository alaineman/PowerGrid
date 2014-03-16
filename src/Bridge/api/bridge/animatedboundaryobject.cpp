#include "animatedboundaryobject.h"

#include "animatedobject.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimatedBoundaryObject, Boundary)
IMPL_RSCLASS_GET(AnimatedBoundaryObject)

IMPL_OBJECT_METHOD(AnimatedBoundaryObject, getAnimatedObject, AnimatedObject)

} // namespace bridge
} // namespace api
