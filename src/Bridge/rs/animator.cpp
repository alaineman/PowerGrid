#include "animator.h"

#include "animation.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Animator)
IMPL_RSCLASS_GET(Animator)

IMPL_OBJECT_METHOD(Animator, getAnimation, Animation)

} // namespace bridge
