#ifndef ITEMNODE_H
#define ITEMNODE_H

#include "node.h"

namespace world{

class ItemNode : public Node {
private:
    Q_DISABLE_COPY(ItemNode)
    jint id;
    jint stacksize;
public:
    ItemNode(jobject obj) : Node(obj){}
    jint getId(bool useCache = true);
    jint getStackSize(bool useCache = true);
};

}

#endif // ITEMNODE_H
