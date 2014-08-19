#ifndef API_BRIDGE_ANIMATEDFLOOROBJECT_H
#define API_BRIDGE_ANIMATEDFLOOROBJECT_H

#include "MethodHelper.h"
#include "floordecoration.h"


namespace RS {

class AnimatedObject;
class AnimatedFloorObject : public FloorDecoration {
public:
    RS_OBJECT(AnimatedFloorObject)

    JACE_PROXY_API AnimatedObject getAnimatedObject();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_ANIMATEDFLOOROBJECT_H
