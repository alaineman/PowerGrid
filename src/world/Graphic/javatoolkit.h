#ifndef JAVATOOLKIT_H
#define JAVATOOLKIT_H

#include "graphicstoolkit.h"

namespace world{

class JavaToolkit : public GraphicsToolkit {
private:
    Q_DISABLE_COPY(JavaToolkit)
public:
    JavaToolkit(jobject obj) : GraphicsToolkit(obj){}
};

}
#endif // JAVATOOLKIT_H
