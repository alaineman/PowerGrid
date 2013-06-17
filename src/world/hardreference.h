#ifndef HARDREFERENCE_H
#define HARDREFERENCE_H

#include "Node/cachablenode.h"

namespace world{

class HardReference : public CachableNode {
private:
    Q_DISABLE_COPY(HardReference)
    jni::JNIObject* referent;
public:
    HardReference(jobject obj) : CachableNode(obj){}
    JNIObject* getReferent(bool useCache = true);
};

}

#endif // HARDREFERENCE_H
