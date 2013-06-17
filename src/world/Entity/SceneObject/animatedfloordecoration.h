#ifndef ANIMATEDFLOORDECORATION_H
#define ANIMATEDFLOORDECORATION_H

#include "Entity/renderableentity.h"

namespace world{

class AnimatedFloorDecoration : public RenderableEntity{
private:
    Q_DISABLE_COPY(AnimatedFloorDecoration)
public:
    AnimatedFloorDecoration(jobject obj) : RenderableEntity(obj){}
};

}

#endif // ANIMATEDFLOORDECORATION_H
