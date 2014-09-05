#ifndef API_BRIDGE_PROJECTILENODE_H
#define API_BRIDGE_PROJECTILENODE_H

#include "MethodHelper.h"
#include "animable.h"
using namespace java::lang;


namespace RS {

class Projectile;
class ProjectileNode : public Animable {
public:
    RS_OBJECT(ProjectileNode)

    JACE_PROXY_API Projectile getProjectile();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_PROJECTILENODE_H
