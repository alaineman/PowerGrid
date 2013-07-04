#ifndef ANIMATEDBOUNDARY_H
#define ANIMATEDBOUNDARY_H

#include "Entity/renderableentity.h"
#include "objectcomposite.h"

namespace world {

class AnimatedBoundary : public RenderableEntity {
private:
    Q_DISABLE_COPY(AnimatedBoundary)
    ObjectComposite* composite;
public:
    AnimatedBoundary(jobject obj) : RenderableEntity(obj) {}
    ObjectComposite* getComposite(bool useCache = true);
};

}


#endif // ANIMATEDBOUNDARY_H
