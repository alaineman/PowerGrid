#ifndef API_BRIDGE_ANIMATEDANIMABLEOBJECT_H
#define API_BRIDGE_ANIMATEDANIMABLEOBJECT_H

#include "MethodHelper.h"
#include "animable.h"


namespace RS {

class AnimatedObject;

class AnimatedAnimableObject : public Animable {
public:
    RS_OBJECT(AnimatedAnimableObject)

    JACE_PROXY_API AnimatedObject getAnimatedObject();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_ANIMATEDANIMABLEOBJECT_H
