#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "animableentity.h"
#include "animator.h"

namespace world{

class Projectile : public AnimableEntity{
private:
    Q_DISABLE_COPY(Projectile)
    jint id;
    jint speed;
    jint targetindex;
    Animator* animator;
public:
    Projectile(jobject obj) : AnimableEntity(obj){}
    jint getId(bool useCache = true);
    jint getSpeed(bool useCache = true);
    jint getTargetIndex(bool useCache = true);
    Animator* getAnimator(bool useCache = true);
};

}
#endif // PROJECTILE_H
