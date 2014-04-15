#include "playerdef.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(PlayerDef)
IMPL_RSCLASS_GET(PlayerDef)

IMPL_ARRAY_METHOD(PlayerDef, getBodypartColors, JInt)
IMPL_ARRAY_METHOD(PlayerDef, getEquipment, JInt)
IMPL_PRIMITIVE_METHOD(PlayerDef, isFemale, JBoolean)
IMPL_PRIMITIVE_METHOD(PlayerDef, getID, JInt)
IMPL_PRIMITIVE_METHOD(PlayerDef, getModelHash, JLong)

} // namespace bridge
} // namespace api
