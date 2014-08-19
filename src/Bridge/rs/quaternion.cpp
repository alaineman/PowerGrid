#include "quaternion.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Quaternion)
IMPL_RSCLASS_GET(Quaternion)

IMPL_PRIMITIVE_METHOD(Quaternion, getA, JFloat)
IMPL_PRIMITIVE_METHOD(Quaternion, getX, JFloat)
IMPL_PRIMITIVE_METHOD(Quaternion, getY, JFloat)
IMPL_PRIMITIVE_METHOD(Quaternion, getZ, JFloat)

} // namespace bridge

