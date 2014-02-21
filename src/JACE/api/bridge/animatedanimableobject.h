#ifndef API_BRIDGE_ANIMATEDANIMABLEOBJECT_H
#define API_BRIDGE_ANIMATEDANIMABLEOBJECT_H

#include "MethodHelper.h"
#include "animable.h"

namespace api {
namespace bridge {

class AnimatedObject;

class AnimatedAnimableObject : public Animable {
public:
    RS_OBJECT(AnimatedAnimableObject)

    JACE_PROXY_API AnimatedObject getAnimatedObject();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMATEDANIMABLEOBJECT_H
