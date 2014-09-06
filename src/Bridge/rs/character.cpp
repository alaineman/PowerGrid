#include "character.h"
#include "animator.h"
#include "linkedlist.h"
#include "abstractmodel.h"
#include "overheadmessage.h"
#include "passiveanimator.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Character, Animable)
IMPL_RSCLASS_GET(Character)

IMPL_OBJECT_METHOD(Character, getActiveAnimator, Animator)
IMPL_PRIMITIVE_METHOD(Character, getAnimationID, JInt)
IMPL_ARRAY_METHOD(Character, getAnimationQueue, JInt)
IMPL_OBJECT_METHOD(Character, getCombatList, LinkedList)
IMPL_PRIMITIVE_METHOD(Character, getHeight, JInt)
IMPL_PRIMITIVE_METHOD(Character, getInteracting, JInt)
IMPL_PRIMITIVE_METHOD(Character, getLocalX, JInt)
IMPL_PRIMITIVE_METHOD(Character, getLocalY, JInt)
IMPL_PRIMITIVE_METHOD(Character, getLocationX, JInt)
IMPL_PRIMITIVE_METHOD(Character, getLocationY, JInt)
IMPL_ARRAY_METHOD(Character, getModels, AbstractModel)
IMPL_PRIMITIVE_METHOD(Character, getMovementSpeed, JInt)
IMPL_PRIMITIVE_METHOD(Character, getOrientation, JInt)
IMPL_OBJECT_METHOD(Character, getOverheadMessage, OverheadMessage)
IMPL_OBJECT_METHOD(Character, getPassiveAnimator, PassiveAnimator)

} // namespace bridge
