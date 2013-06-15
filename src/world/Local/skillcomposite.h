#ifndef SKILLCOMPOSITE_H
#define SKILLCOMPOSITE_H

#include "jniobject.h"

namespace world{

class SkillComposite : public jni::JNIObject{
private:
    Q_DISABLE_COPY(SkillComposite)
    jboolean memberonly;
    jint maxlevel;
public:
    SkillComposite(jobject obj) : JNIObject(obj){}
    jboolean isMembersOnly();
    jint getMaxLevel();
};

}

#endif // SKILLCOMPOSITE_H
