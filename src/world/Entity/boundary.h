#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "renderableentity.h"
#include "Graphic/model.h"

namespace world {

class Boundary : public RenderableEntity {
private:
    Q_DISABLE_COPY(Boundary)
    jint id;
    Model* model;
public:
    Boundary(jobject obj) : RenderableEntity(obj) {}
    jint getId(bool useCache = true);
    Model* getModel(bool useCache = true);
};

}

#endif // BOUNDARY_H
