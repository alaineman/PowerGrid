#ifndef OPENGLTOOLKIT_H
#define OPENGLTOOLKIT_H

#include "graphicstoolkit.h"

namespace world{

class OpenGLToolkit : public GraphicsToolkit {
private:
    Q_DISABLE_COPY(OpenGLToolkit)
public:
    OpenGLToolkit(jobject obj) : GraphicsToolkit(obj){}
};

}

#endif // OPENGLTOOLKIT_H
