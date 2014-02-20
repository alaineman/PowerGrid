#include "hintarrow.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(HintArrow)
IMPL_RSCLASS_GET(HintArrow)

IMPL_PRIMITIVE_METHOD(HintArrow, getHeadIconIndex, JInt)
IMPL_PRIMITIVE_METHOD(HintArrow, getLocalX, JInt)
IMPL_PRIMITIVE_METHOD(HintArrow, getLocalY, JInt)
IMPL_PRIMITIVE_METHOD(HintArrow, getPlane, JInt)
IMPL_PRIMITIVE_METHOD(HintArrow, getTargetIndex, JInt)
IMPL_PRIMITIVE_METHOD(HintArrow, getType, JInt)

} // namespace bridge
} // namespace api
