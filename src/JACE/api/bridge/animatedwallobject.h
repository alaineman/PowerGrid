#ifndef API_BRIDGE_ANIMATEDWALLOBJECT_H
#define API_BRIDGE_ANIMATEDWALLOBJECT_H

#include "MethodHelper.h"
#include "java/lang/object.h"
#include "walldecoration.h"


namespace api {
namespace bridge {

class AnimatedObject;
class AnimatedWallObject : public WallDecoration {
public:
    RS_OBJECT(AnimatedWallObject)

    JACE_PROXY_API AnimatedObject getAnimatedObject();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMATEDWALLOBJECT_H
