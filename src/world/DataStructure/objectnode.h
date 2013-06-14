#ifndef OBJECTNODE_H
#define OBJECTNODE_H

#include "jniobject.h"

namespace world{

class ObjectNode : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ObjectNode)
    JNIObject* object;
public:
    ObjectNode(jobject obj) : JNIObject(obj){}
    JNIObject* getObject();
};

}


#endif // OBJECTNODE_H
