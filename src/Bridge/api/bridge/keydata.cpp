#include "keydata.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(KeyData)
IMPL_RSCLASS_GET(KeyData)

IMPL_PRIMITIVE_METHOD(KeyData, getCharacter, JChar)
IMPL_PRIMITIVE_METHOD(KeyData, getCode, JInt)
IMPL_PRIMITIVE_METHOD(KeyData, getTime, JLong)
IMPL_PRIMITIVE_METHOD(KeyData, getType, JInt)

} // namespace bridge
} // namespace api
