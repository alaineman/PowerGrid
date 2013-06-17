#ifndef SOFTREFERENCE_H
#define SOFTREFERENCE_H

#include "Node/cachablenode.h"

namespace world{

class SoftReference : public CachableNode {
private:
    Q_DISABLE_COPY(SoftReference)
public:
    SoftReference(jobject obj) : CachableNode(obj){}
    SoftReference* getReferent(bool useCache = true);

};

}

#endif // SOFTREFERENCE_H
