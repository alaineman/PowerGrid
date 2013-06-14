#ifndef ANIMABLEENTITY_H
#define ANIMABLEENTITY_H

#include "renderableentity.h"

namespace world {

class AnimableEntity : public RenderableEntity {
private:
    Q_DISABLE_COPY(AnimableEntity)
    jshort minx;
    jshort maxx;
    jshort miny;
    jshort maxy;
public:
    AnimableEntity(jobject obj) : RenderableEntity(obj) {}
    jshort getMinX(bool useCache = true);
    jshort getMaxX(bool useCache = true);
    jshort getMinY(bool useCache = true);
    jshort getMaxY(bool useCache = true);
};

}

#endif // ANIMABLEENTITY_H
