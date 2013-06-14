#ifndef RENDERABLEENTITY_H
#define RENDERABLEENTITY_H

#include "entity.h"

namespace world {

class RenderableEntity : public Entity {
private:
    Q_DISABLE_COPY(RenderableEntity)
    jbyte plane;
public:
    RenderableEntity(jobject obj) : Entity(obj) {}
    jbyte getPlane(bool useCache = true);
};

}

#endif // RENDERABLEENTITY_H
