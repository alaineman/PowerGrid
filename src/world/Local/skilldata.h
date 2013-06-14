#ifndef SKILLDATA_H
#define SKILLDATA_H

#include "jniobject.h"

namespace world {

class SkillData : public jni::JNIObject{
private:
    Q_DISABLE_COPY(SkillData)
public:
    SkillData(jobject obj) : JNIObject(obj){}
};

}

#endif // SKILLDATA_H
