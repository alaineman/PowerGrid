#ifndef HARDREFERENCE_H
#define HARDREFERENCE_H

#include "reference.h"

namespace world{

class HardReference : public Reference {
private:
    Q_DISABLE_COPY(HardReference)
public:
    HardReference(jobject obj) : Reference(obj){}
};

}

#endif // HARDREFERENCE_H
