#ifndef JAVATOOLKIT_H
#define JAVATOOLKIT_H

#include "graphicstoolkit.h"

namespace world{

class JavaToolkit : public GraphicsToolkit {
private:
    Q_DISABLE_COPY(JavaToolkit)    
    jfloat absolutex;
    jfloat multiplierx;
    jfloat absolutey;
    jfloat multipliery;
    Matrix4f* matrix4f;
public:
    JavaToolkit(jobject obj) : GraphicsToolkit(obj){}    
    jfloat getAbsoluteX(bool useCache = true);
    jfloat getXMultiplier(bool useCache = true);
    jfloat getAbsoluteY(bool useCache = true);
    jfloat getYMultiplier(bool useCache = true);
    Matrix4f* getMatrix4f(bool useCache = true);
};

}
#endif // JAVATOOLKIT_H
