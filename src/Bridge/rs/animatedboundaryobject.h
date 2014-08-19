#ifndef API_BRIDGE_ANIMATEDBOUNDARYOBJECT_H
#define API_BRIDGE_ANIMATEDBOUNDARYOBJECT_H

#include "MethodHelper.h"
#include "boundary.h"


namespace RS {

class AnimatedObject;

class AnimatedBoundaryObject : public Boundary {
public:
    RS_OBJECT(AnimatedBoundaryObject)

    JACE_PROXY_API AnimatedObject getAnimatedObject();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_ANIMATEDBOUNDARYOBJECT_H
