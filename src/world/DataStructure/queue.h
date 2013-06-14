#ifndef QUEUE_H
#define QUEUE_H

#include "jniobject.h"
#include "Node/cachablenode.h"

namespace world {

class Queue : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Queue)
    CachableNode* sentinel;
    CachableNode* current;
public:
    Queue(jobject obj) : JNIObject(obj){}
    CachableNode* getSentinel(bool useCache = true);
    CachableNode* getCurrent(bool useCache = true);
};

}

#endif // QUEUE_H
