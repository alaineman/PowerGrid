#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "jniobject.h"

namespace world {

class Vector3D : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Vector3D)
public:
    Vector3D(jobject obj)  : JNIObject(obj) {}
    jfloat getLocalX();
    jfloat getLocalY();
};

}
#endif // VECTOR3D_H
