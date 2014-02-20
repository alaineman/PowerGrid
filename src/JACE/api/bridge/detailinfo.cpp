#include "detailinfo.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(DetailInfo)
IMPL_RSCLASS_GET(DetailInfo)

IMPL_PRIMITIVE_METHOD(DetailInfo, getLevel, JInt)

} // namespace bridge
} // namespace api
