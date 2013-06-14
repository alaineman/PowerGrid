#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H

#include "model.h"

namespace world{

class OpenGLModel : public Model {
private:
    Q_DISABLE_COPY(OpenGLModel)
public:
    OpenGLModel(jobject obj) : Model(obj){}
};

}

#endif // OPENGLMODEL_H
