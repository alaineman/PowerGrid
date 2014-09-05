#ifndef API_BRIDGE_PROJECTILE_H
#define API_BRIDGE_PROJECTILE_H

#include "MethodHelper.h"
#include "animable.h"
using namespace java::lang;


namespace RS {

class Animator;
class Projectile : public Animable {
public:
    RS_OBJECT(Projectile)

    JACE_PROXY_API JInt getAnimationID();
    JACE_PROXY_API Animator getAnimator();
    JACE_PROXY_API JInt getTarget();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_PROJECTILE_H
