#ifndef API_BRIDGE_CHARACTER_H
#define API_BRIDGE_CHARACTER_H

#include "MethodHelper.h"
#include "animable.h"

namespace api {
namespace bridge {

class Animator;
class LinkedList;
class AbstractModel;
class OverheadMessage;
class PassiveAnimator;

class Character : public Animable {
public:
    RS_OBJECT(Character)

    JACE_PROXY_API Animator getActiveAnimator();
    JACE_PROXY_API JInt getAnimationID();
    JACE_PROXY_API QList<JInt> getAnimationQueue();
    JACE_PROXY_API LinkedList getCombatList();
    JACE_PROXY_API JInt getHeight();
    JACE_PROXY_API JInt getInteracting();
    JACE_PROXY_API JInt getLocalX();
    JACE_PROXY_API JInt getLocalY();
    JACE_PROXY_API JInt getLocationX();
    JACE_PROXY_API JInt getLocationY();
    JACE_PROXY_API QList<AbstractModel> getModels();
    JACE_PROXY_API JInt getMovementSpeed();
    JACE_PROXY_API JInt getOrientation();
    JACE_PROXY_API OverheadMessage getOverheadMessage();
    JACE_PROXY_API PassiveAnimator getPassiveAnimator();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CHARACTER_H
