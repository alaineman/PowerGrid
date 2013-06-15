#ifndef SKILLDATA_H
#define SKILLDATA_H

#include "jniobject.h"
#include "skillcomposite.h"


namespace world {

class Skill : public jni::JNIObject{
private:
    Q_DISABLE_COPY(Skill)
    jint experience;
    jint baselevel;
    jint currentlevel;
    SkillComposite* composite;
public:
    Skill(jobject obj) : JNIObject(obj){}
    jint getExperience(bool useCache = true);
    jint getBaseLevel(bool useCache = true);
    jint getCurrentLevel(bool useCache = true);
    SkillComposite* getComposite(bool useCache = true);
};

}

#endif // SKILLDATA_H
