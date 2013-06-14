#ifndef MODEL_H
#define MODEL_H

#include "jniobject.h"

namespace world{

class Model : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Model)
public:
    Model(jobject obj) : JNIObject(obj){}
};

}

#endif // MODEL_H
