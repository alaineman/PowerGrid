#include "baseinfo.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(BaseInfo)
IMPL_RSCLASS_GET(BaseInfo)

IMPL_PRIMITIVE_METHOD(BaseInfo, getMinX, JInt)
IMPL_PRIMITIVE_METHOD(BaseInfo, getMinY, JInt)

} // namespace bridge
