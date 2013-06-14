#ifndef NPCCOMPOSITE_H
#define NPCCOMPOSITE_H

#include "jniobject.h"
#include "jnistring.h"

namespace world{

class NpcComposite : public jni::JNIObject {
private:
    Q_DISABLE_COPY(NpcComposite)
    jint id;
    jni::JNIString* name;
    vector<jni::JNIString*> actions;
public:
    NpcComposite(jobject obj) : JNIObject(obj){}
    jint getId(bool useCache = true);
    jni::JNIString* getName(bool useCache = true);
    vector<jni::JNIString*> getActions(bool useCache = true);
    jint getCombatLevel(bool useCache = true);
    jint getPrayerIconIndex(bool useCache = true);
};

}

#endif // NPCCOMPOSITE_H
