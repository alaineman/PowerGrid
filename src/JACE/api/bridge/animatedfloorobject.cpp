#include "animatedfloorobject.h"
#include "animatedobject.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(AnimatedFloorObject, FloorDecoration)
IMPL_RSCLASS_GET(AnimatedFloorObject)

IMPL_OBJECT_METHOD(AnimatedFloorObject, getAnimatedObject, AnimatedObject)

} // namespace bridge
} // namespace api
