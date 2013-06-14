#ifndef GROUNDENTITY_H
#define GROUNDENTITY_H

#include "renderableentity.h"

namespace world {

class GroundEntity : public RenderableEntity {
private:
    Q_DISABLE_COPY(GroundEntity)
public:
    GroundEntity(jobject obj) : RenderableEntity(obj) {}
};

}

#endif // GROUNDENTITY_H
