#include "animatedfloorobject.h"
#include "animatedobject.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimatedFloorObject, FloorDecoration)
IMPL_RSCLASS_GET(AnimatedFloorObject)

IMPL_OBJECT_METHOD(AnimatedFloorObject, getAnimatedObject, AnimatedObject)

} // namespace bridge
