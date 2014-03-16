#include "animation.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Animation)
IMPL_RSCLASS_GET(Animation)

IMPL_PRIMITIVE_METHOD(Animation, getID, JInt)
IMPL_PRIMITIVE_METHOD(Animation, getShieldDisplayed, JInt)
IMPL_PRIMITIVE_METHOD(Animation, getWalkingProperties, JInt)
IMPL_PRIMITIVE_METHOD(Animation, getWeaponDisplayed, JInt)

}
}
