#ifndef NODE_H
#define NODE_H

#include "jniobject.h"

namespace world{

class Node : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Node)
    jlong uid;
    Node* previous;
    Node* next;
public:
    Node(jobject obj) : JNIObject(obj){}
    jlong getUid(bool useCache = true);
    Node* getPrevious(bool useCache = true);
    Node* getNext(bool useCache = true);
};

}

#endif // NODE_H
