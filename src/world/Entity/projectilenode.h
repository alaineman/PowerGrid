#ifndef PROJECTILENODE_H
#define PROJECTILENODE_H

#include "jniobject.h"

namespace world{

class ProjectileNode : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ProjectileNode)
public:
    ProjectileNode(jobject obj) : JNIObject(obj){}
};

}

#endif // PROJECTILENODE_H
