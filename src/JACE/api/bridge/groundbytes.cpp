#include "groundbytes.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(GroundBytes)
IMPL_RSCLASS_GET(GroundBytes)

IMPL_ARRAY3_METHOD(GroundBytes, getBytes, JByte)

} // namespace bridge
} // namespace api
