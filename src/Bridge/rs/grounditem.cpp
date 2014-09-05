#include "grounditem.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(GroundItem, GroundEntity)
IMPL_RSCLASS_GET(GroundItem)

IMPL_PRIMITIVE_METHOD(GroundItem, getID, JInt)
IMPL_PRIMITIVE_METHOD(GroundItem, getStackSize, JInt)

} // namespace bridge
