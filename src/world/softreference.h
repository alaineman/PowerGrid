#ifndef SOFTREFERENCE_H
#define SOFTREFERENCE_H

#include "reference.h"

namespace world{

class SoftReference : public Reference {
private:
    Q_DISABLE_COPY(SoftReference)
public:
    SoftReference(jobject obj) : Reference(obj){}
};

}

#endif // SOFTREFERENCE_H
