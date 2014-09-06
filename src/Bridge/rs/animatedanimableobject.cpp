#include "animatedanimableobject.h"

#include "animatedobject.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimatedAnimableObject, Animable)
IMPL_RSCLASS_GET(AnimatedAnimableObject)

IMPL_OBJECT_METHOD(AnimatedAnimableObject, getAnimatedObject, AnimatedObject)

} // namespace bridge
