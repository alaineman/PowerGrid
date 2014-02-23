#include "player.h"
#include "modelld.h"
#include "playerdef.h"
#include "java/lang/string.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Player, Character)
IMPL_RSCLASS_GET(Player)

IMPL_PRIMITIVE_METHOD(Player, getGender, JByte)
IMPL_PRIMITIVE_METHOD(Player, getLevel, JInt)
IMPL_OBJECT_METHOD(Player, getModel, ModelLD)
IMPL_OBJECT_METHOD(Player, getName, String)
IMPL_OBJECT_METHOD(Player, getNameSuffix, String)
IMPL_PRIMITIVE_METHOD(Player, getPKHeadIconIndex, JInt)
IMPL_OBJECT_METHOD(Player, getPlayerDef, PlayerDef)
IMPL_PRIMITIVE_METHOD(Player, getPrayerHeadIconIndex, JInt)
IMPL_OBJECT_METHOD(Player, getTitle, String)

} // namespace bridge
} // namespace api
