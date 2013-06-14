#ifndef ANIMATION_H
#define ANIMATION_H

#include "jniobject.h"

namespace world{

class Animation : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Animation)
    jint id;
public:
    Animation(jobject obj) : JNIObject(obj){}
    jint getId(bool useCache = true);
};

}
#endif // ANIMATION_H
