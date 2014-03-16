#include "interactableanimator.h"
#include "interactable.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(InteractableAnimator, Animator)
IMPL_RSCLASS_GET(InteractableAnimator)

IMPL_OBJECT_METHOD(InteractableAnimator, getEntity, Interactable)

} // namespace bridge
} // namespace api
