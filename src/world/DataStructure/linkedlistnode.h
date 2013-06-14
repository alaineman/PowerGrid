#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include "jniobject.h"

namespace world{

class LinkedListNode : public jni::JNIObject{
private:
    Q_DISABLE_COPY(LinkedListNode)
    LinkedListNode* next;
public:
    LinkedListNode(jobject obj) : JNIObject(obj){}
    LinkedListNode* getNext(bool useCache = true);
};

}

#endif // LINKEDLISTNODE_H
