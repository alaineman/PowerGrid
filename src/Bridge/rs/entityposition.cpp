#include "entityposition.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(EntityPosition)
IMPL_RSCLASS_GET(EntityPosition)

IMPL_PRIMITIVE_METHOD(EntityPosition, getHeight, JFloat)
IMPL_PRIMITIVE_METHOD(EntityPosition, getLocalX, JFloat)
IMPL_PRIMITIVE_METHOD(EntityPosition, getLocalY, JFloat)

} // namespace bridge
