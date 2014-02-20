#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Animator;
class Interactable;
class ObjectDefLoader;

class AnimatedObject : public Object {
public:
    RS_OBJECT(AnimatedObject)

    JACE_PROXY_API Animator getAnimator();
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API Interactable getInteractable();
    JACE_PROXY_API JInt getLocalX();
    JACE_PROXY_API JInt getLocalY();
    JACE_PROXY_API JInt getLocationX();
    JACE_PROXY_API JInt getLocationY();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
    JACE_PROXY_API JInt getOrientation();

private:
    DECLARE_FRIENDS
};

}
}

#endif // ANIMATEDOBJECT_H
