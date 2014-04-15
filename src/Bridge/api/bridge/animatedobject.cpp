#include "animatedobject.h"

#include "animator.h"
#include "interactable.h"
#include "objectdefloader.h"
#include "modelld.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(AnimatedObject)
IMPL_RSCLASS_GET(AnimatedObject)

IMPL_OBJECT_METHOD(AnimatedObject, getAnimator, Animator)
IMPL_PRIMITIVE_METHOD(AnimatedObject, getID, JInt)
IMPL_OBJECT_METHOD(AnimatedObject, getInteractable, Interactable)
IMPL_PRIMITIVE_METHOD(AnimatedObject, getLocalX, JInt)
IMPL_PRIMITIVE_METHOD(AnimatedObject, getLocalY, JInt)
IMPL_PRIMITIVE_METHOD(AnimatedObject, getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(AnimatedObject, getLocationY, JInt)
IMPL_OBJECT_METHOD(AnimatedObject, getModel, ModelLD)
IMPL_OBJECT_METHOD(AnimatedObject, getObjectDefLoader, ObjectDefLoader)
IMPL_PRIMITIVE_METHOD(AnimatedObject, getOrientation, JInt)

}
}
