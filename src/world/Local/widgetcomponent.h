#ifndef WIDGETCOMPONENT_H
#define WIDGETCOMPONENT_H

#include "jniobject.h"
#include "jnistring.h"
#include "Entity/animator.h"

namespace world {

class WidgetComponent : public jni::JNIObject{
private:
    Q_DISABLE_COPY(WidgetComponent)
    vector<WidgetComponent*> children;
    vector<jni::JNIString*> actions;
    Animator* animator;
public:
    WidgetComponent(jobject obj) : JNIObject(obj){}
    vector<WidgetComponent*> getChildren(bool useCache = true);
    vector<jni::JNIString*> getActions(bool useCache = true);
    Animator* getAnimator(bool useCache = true);
};

}

#endif // WIDGETCOMPONENT_H
