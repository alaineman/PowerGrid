#include "projectilenode.h"
#include "projectile.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ProjectileNode, Animable)
IMPL_RSCLASS_GET(ProjectileNode)

IMPL_OBJECT_METHOD(ProjectileNode, getProjectile, Projectile)

} // namespace bridge

