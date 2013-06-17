#ifndef CACHABLENODE_H
#define CACHABLENODE_H

#include "node.h"
#include "jniobject.h"

namespace world{
class CachableNode : public Node {
private:
    Q_DISABLE_COPY(CachableNode)
    CachableNode* previous;
    CachableNode* next;
    jlong uid;
public:
    CachableNode(jobject obj) : Node(obj){}
    jlong getCachableUid(bool useCache = true);
    CachableNode* getPreviousCachable(bool useCache = true);
    CachableNode* getNextCachable(bool useCache = true);
};
}

#endif // CACHABLENODE_H
