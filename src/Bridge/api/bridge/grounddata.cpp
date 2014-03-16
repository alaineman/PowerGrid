#include "grounddata.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(GroundData)
IMPL_RSCLASS_GET(GroundData)

IMPL_ARRAY2_METHOD(GroundData, getBlocks, JInt)
IMPL_PRIMITIVE_METHOD(GroundData, getX, JInt)
IMPL_PRIMITIVE_METHOD(GroundData, getY, JInt)

} // namespace bridge
} // namespace api
