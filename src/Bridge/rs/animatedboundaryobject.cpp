#include "animatedboundaryobject.h"

#include "animatedobject.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimatedBoundaryObject, Boundary)
IMPL_RSCLASS_GET(AnimatedBoundaryObject)

IMPL_OBJECT_METHOD(AnimatedBoundaryObject, getAnimatedObject, AnimatedObject)

} // namespace bridge
