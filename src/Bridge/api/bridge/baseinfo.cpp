#include "baseinfo.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(BaseInfo)
IMPL_RSCLASS_GET(BaseInfo)

IMPL_PRIMITIVE_METHOD(BaseInfo, getX, JInt)
IMPL_PRIMITIVE_METHOD(BaseInfo, getY, JInt)

} // namespace bridge
} // namespace api
