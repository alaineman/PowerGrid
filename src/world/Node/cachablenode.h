#ifndef CACHABLENODE_H
#define CACHABLENODE_H

#include "node.h"
#include "jniobject.h"

namespace world{
class CachableNode : public Node {
private:
    Q_DISABLE_COPY(CachableNode)
public:
    CachableNode(jobject obj) : Node(obj){}
};
}

#endif // CACHABLENODE_H
