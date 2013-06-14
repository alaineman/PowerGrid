#ifndef DEQUENODE_H
#define DEQUENODE_H

#include "jniobject.h"
#include "node.h"
#include "DataStructure/deque.h"

namespace world{

class DequeNode : public Node {
private:
    Q_DISABLE_COPY(DequeNode)
    Deque* deque;
public:
    DequeNode(jobject obj) : Node(obj){}
    Deque* getDeque(bool useCache = true);
};

}

#endif // DEQUENODE_H
