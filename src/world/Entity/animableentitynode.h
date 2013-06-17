#ifndef ANIMABLEENTITYNODE_H
#define ANIMABLEENTITYNODE_H

#include "jniobject.h"
#include "animableentity.h"

namespace world{

class AnimableEntityNode : public jni::JNIObject {
private:
    Q_DISABLE_COPY(AnimableEntityNode)
    AnimableEntity* entity;
    AnimableEntityNode* next;
public:
    AnimableEntityNode(jobject obj) : JNIObject(obj){}
    AnimableEntity* getEntity(bool useCache = true);
    AnimableEntityNode* getNext(bool useCache = true);
};

}

#endif // ANIMABLEENTITYNODE_H
