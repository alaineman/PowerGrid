#ifndef WALLDECORATION_H
#define WALLDECORATION_H

#include "Entity/renderableentity.h"
#include "Graphic/model.h"

namespace world {

class WallDecoration : public RenderableEntity {
private:
    Q_DISABLE_COPY(WallDecoration)
    jint id;
    Model* model;

public:
    WallDecoration(jobject obj) : RenderableEntity(obj) {}
    jint getId(bool useCache = true);
    Model* getModel(bool useCache = true);
};

}

#endif // WALLDECORATION_H
