#ifndef FLOORDECORATION_H
#define FLOORDECORATION_H

#include "Entity/renderableentity.h"

namespace world{

class FloorDecoration : public RenderableEntity{
private:
    Q_DISABLE_COPY(FloorDecoration)
public:
    FloorDecoration(jobject obj) : RenderableEntity(obj){}
};

}

#endif // FLOORDECORATION_H
