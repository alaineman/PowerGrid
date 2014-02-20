#include "animatedobject.h"

//#include "animator.h"
//#include "interactable.h"
//#include "objectdefloader.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(AnimatedObject)
IMPL_RSCLASS_GET(AnimatedObject)

//IMPL_OBJECT_METHOD(AnimatedObject, getAnimator, Animator)
IMPL_OBJECT_METHOD(AnimatedObject, getID, JInt)
//IMPL_OBJECT_METHOD(AnimatedObject, getInteractable, Interactable)
IMPL_OBJECT_METHOD(AnimatedObject, getLocalX, JInt)
IMPL_OBJECT_METHOD(AnimatedObject, getLocalY, JInt)
IMPL_OBJECT_METHOD(AnimatedObject, getLocationX, JInt)
IMPL_OBJECT_METHOD(AnimatedObject, getLocationY, JInt)
//IMPL_OBJECT_METHOD(AnimatedObject, getObjectDefLoader, ObjectDefLoader)

}
}
