#include "mousedata.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(MouseData)
IMPL_RSCLASS_GET(MouseData)

IMPL_PRIMITIVE_METHOD(MouseData, getType, JInt)
IMPL_PRIMITIVE_METHOD(MouseData, getTime, JLong)
IMPL_PRIMITIVE_METHOD(MouseData, getX, JInt)
IMPL_PRIMITIVE_METHOD(MouseData, getY, JInt)

} // namespace bridge
