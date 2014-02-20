#include "animator.h"

#include "animation.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Animator)
IMPL_RSCLASS_GET(Animator)

IMPL_OBJECT_METHOD(Animator, getAnimation, Animation)

} // namespace bridge
} // namespace api
