#ifndef OBJECTDEFINITION_H
#define OBJECTDEFINITION_H

#include "jniobject.h"
#include "Graphic/model.h"
#include "Entity/animator.h"

namespace world {

class ObjectCompsite : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ObjectCompsite)
    jboolean walkable;
    jni::JNIString* name;
    vector<jni::JNIString*> actions;
public:
    ObjectCompsite(jobject obj) : JNIObject(obj) {}
    jboolean isWalkable(bool useCache = true);
    jni::JNIString* getName(bool useCache = true);
    vector<jni::JNIString*> getActions(bool useCache = true);

};

}

#endif // OBJECTDEFINITION_H
