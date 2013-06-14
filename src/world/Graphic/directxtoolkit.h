#ifndef DIRECTXTOOLKIT_H
#define DIRECTXTOOLKIT_H

#include "graphicstoolkit.h"

namespace world{

class DirectXToolkit : public GraphicsToolkit {
private:
    Q_DISABLE_COPY(DirectXToolkit)
public:
    DirectXToolkit(jobject obj) : GraphicsToolkit(obj){}
};

}

#endif // DIRECTXTOOLKIT_H
