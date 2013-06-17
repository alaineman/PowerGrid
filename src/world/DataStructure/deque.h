#ifndef DEQUE_H
#define DEQUE_H

#include "jniobject.h"
#include "Node/node.h"

namespace world {

class Deque : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Deque)
    Node* sentinel;
public:
    Deque(jobject obj) : JNIObject(obj){}
    Node* getSentinel(bool useCache = true);
};

}

#endif // DEQUE_H
