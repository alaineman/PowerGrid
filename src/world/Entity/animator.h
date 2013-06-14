#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "animation.h"

namespace world{

class Animator : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Animator)
    Animation* animation;
public:
    Animator(jobject obj) : JNIObject(obj){}
    Animation* getAnimation(bool useCache = true);
};

}
#endif // ANIMATOR_H
