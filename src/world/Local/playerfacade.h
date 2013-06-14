#ifndef PLAYERFACADE_H
#define PLAYERFACADE_H

#include "jniobject.h"
#include "varps.h"
#include "skilldata.h"

namespace world{

class PlayerFacade : public jni::JNIObject {
private:
    Q_DISABLE_COPY(PlayerFacade)
    Varps* varps;
    vector<SkillData*> skilldata;
public:
    PlayerFacade();
    Varps* getVarps(bool useCache = true);
    vector<SkillData*> getSkillData(bool useCache = true);
};

}

#endif // PLAYERFACADE_H
