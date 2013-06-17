#ifndef PROJECTILENODE_H
#define PROJECTILENODE_H

#include "jniobject.h"
#include "projectile.h"

namespace world{

class ProjectileNode : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ProjectileNode)
    Projectile* projectile;
public:
    ProjectileNode(jobject obj) : JNIObject(obj){}
    Projectile* getProjectile(bool useCache = true);
};

}

#endif // PROJECTILENODE_H
