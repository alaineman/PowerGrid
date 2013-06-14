#ifndef REFERENCE_H
#define REFERENCE_H

#include "jniobject.h"

namespace world{

class Reference : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Reference)
    JNIObject* referent;
public:
    Reference(jobject obj) : JNIObject(obj){}
    JNIObject* getReferent();
};

}
#endif // REFERENCE_H
