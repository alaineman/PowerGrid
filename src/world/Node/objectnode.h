#ifndef OBJECTNODE_H
#define OBJECTNODE_H

#include "Node/node.h"

namespace world{

class ObjectNode : public Node {
private:
    Q_DISABLE_COPY(ObjectNode)
    JNIObject* object;
public:
    ObjectNode(jobject obj) : Node(obj){}
    JNIObject* getObject();
};

}


#endif // OBJECTNODE_H
