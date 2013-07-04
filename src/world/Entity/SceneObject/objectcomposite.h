#ifndef OBJECTCOMPOSITE_H
#define OBJECTCOMPOSITE_H

#include "jniobject.h"
#include "Graphic/model.h"
#include "Entity/animator.h"

namespace world {

class ObjectComposite : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ObjectComposite)
    jint id;
    Model* model;
    Animator* animator1;
    Animator* animator2;
public:
    ObjectComposite(jobject obj) : JNIObject(obj) {}
    jint getId(bool useCache = true);
    Model* getModel(bool useCache = true);
    Animator* getAnimator1(bool useCache = true);
    Animator* getAnimator2(bool useCache = true);
};

}
#endif // OBJECTCOMPOSITE_H
