#ifndef DIRECTXMODEL_H
#define DIRECTXMODEL_H

#include "jniobject.h"

namespace world{

class DirectXModel : public jni::JNIObject {
private:
    Q_DISABLE_COPY(DirectXModel)
public:
    DirectXModel(jobject obj) : JNIObject(obj){}
};

}
#endif // DIRECTXMODEL_H
