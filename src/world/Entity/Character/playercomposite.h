#ifndef PLAYERCOMPOSITE_H
#define PLAYERCOMPOSITE_H

#include "jniobject.h"

namespace world {

class PlayerComposite : public jni::JNIObject {
private:
    Q_DISABLE_COPY(PlayerComposite)
    jint npcId;
    jboolean female;
    jlong modelhash;
    vector<jint> appearance;
public:
    PlayerComposite(jobject obj) : JNIObject(obj){}
    jint getNpcId(bool useCache = true);
    jboolean isFemale(bool useCache = true);
    jlong getModelHash(bool useCache = true);
    vector<jint> getAppearance(bool useCache = true);
};

}

#endif // PLAYERCOMPOSITE_H
