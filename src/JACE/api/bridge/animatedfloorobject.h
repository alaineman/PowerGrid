#ifndef API_BRIDGE_ANIMATEDFLOOROBJECT_H
#define API_BRIDGE_ANIMATEDFLOOROBJECT_H

#include "MethodHelper.h"
#include "floordecoration.h"

namespace api {
namespace bridge {

class AnimatedObject;
class AnimatedFloorObject : public FloorDecoration {
public:
    RS_OBJECT(AnimatedFloorObject)

    JACE_PROXY_API AnimatedObject getAnimatedObject();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMATEDFLOOROBJECT_H
