#include "hardreference.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(HardReference, Reference)
IMPL_RSCLASS_GET(HardReference)

IMPL_OBJECT_METHOD(HardReference, getHardReference, Object)

} // namespace bridge
} // namespace api
