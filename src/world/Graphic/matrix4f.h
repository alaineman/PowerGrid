#ifndef MATRIX4F_H
#define MATRIX4F_H

#include "jniobject.h"

namespace world{

class Matrix4f : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Matrix4f)
    vector<jfloat> matrix;
public:
    Matrix4f(jobject obj) : JNIObject(obj){}
    vector<jfloat> getMatrix();
};

}

#endif // MATRIX4F_H
