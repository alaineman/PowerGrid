#ifndef WIDGETCOMPONENT_H
#define WIDGETCOMPONENT_H

#include "jniobject.h"
#include "jnistring.h"
#include "Entity/animator.h"

namespace world {

class WidgetComponent : public jni::JNIObject{
private:
    Q_DISABLE_COPY(WidgetComponent)
    jint relativex;
    jint relativey;
    jint width;
    jint height;
    jint itemid;
    jint itemstacksize;
    jint textureid;
    jint borderthickness;
    jboolean visible;
    vector<jni::JNIString*> actions;
    Animator* animator;
    vector<WidgetComponent*> children;
public:
    WidgetComponent(jobject obj) : JNIObject(obj){}
    jint getRelativeX(bool useCache = true);
    jint getRelativeY(bool useCache = true);
    jint getWidth(bool useCache = true);
    jint getHeight(bool useCache = true);
    jint getItemId(bool useCache = true);
    jint getItemStackSize(bool useCache = true);
    jint getTextureId(bool useCache = true);
    jint getBorderThickness(bool useCache = true);
    jboolean isVisible(bool useCache = true);
    vector<jni::JNIString*> getActions(bool useCache = true);
    Animator* getAnimator(bool useCache = true);
    vector<WidgetComponent*> getChildren(bool useCache = true);
};

}

#endif // WIDGETCOMPONENT_H
