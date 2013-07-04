#ifndef ANIMATEDWALLDECORATION_H
#define ANIMATEDWALLDECORATION_H

#include "Entity/renderableentity.h"
#include "objectcomposite.h"

namespace world {

class AnimatedWallDecoration : public RenderableEntity {
private:
    Q_DISABLE_COPY(AnimatedWallDecoration)
    ObjectComposite* composite;
public:
    AnimatedWallDecoration(jobject obj) : RenderableEntity(obj) {}
    ObjectComposite* getComposite(bool useCache = true);
};

}


#endif // ANIMATEDWALLDECORATION_H
