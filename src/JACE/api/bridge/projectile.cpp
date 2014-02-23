#include "projectile.h"
#include "animator.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Projectile, Animable)
IMPL_RSCLASS_GET(Projectile)

IMPL_PRIMITIVE_METHOD(Projectile, getAnimationID, JInt)
IMPL_OBJECT_METHOD(Projectile, getAnimator, Animator)
IMPL_PRIMITIVE_METHOD(Projectile, getTarget, JInt)

} // namespace bridge
} // namespace api
