#ifndef ANIMATEDEVENTOBJECT_H
#define ANIMATEDEVENTOBJECT_H

#include "Entity/animableentity.h"
#include "objectcomposite.h"

namespace world {

class AnimatedEventObject : public AnimableEntity {
private:
    Q_DISABLE_COPY(AnimatedEventObject)
    ObjectComposite* composite;
public:
    AnimatedEventObject(jobject obj) : AnimableEntity(obj) {}
    ObjectComposite* getComposite(bool useCache = true);
};

}

#endif // ANIMATEDEVENTOBJECT_H
