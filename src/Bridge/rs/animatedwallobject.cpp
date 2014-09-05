#include "animatedwallobject.h"
#include "animatedobject.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimatedWallObject, WallDecoration)
IMPL_RSCLASS_GET(AnimatedWallObject)

IMPL_OBJECT_METHOD(AnimatedWallObject, getAnimatedObject, AnimatedObject)

} // namespace bridge
