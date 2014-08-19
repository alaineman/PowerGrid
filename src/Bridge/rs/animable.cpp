#include "animable.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Animable, Interactable)
IMPL_RSCLASS_GET(Animable)

IMPL_PRIMITIVE_METHOD(Animable, getMaxX, JShort)
IMPL_PRIMITIVE_METHOD(Animable, getMaxY, JShort)
IMPL_PRIMITIVE_METHOD(Animable, getMinX, JShort)
IMPL_PRIMITIVE_METHOD(Animable, getMinY, JShort)

} // namespace bridge
