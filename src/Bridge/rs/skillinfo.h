#ifndef API_BRIDGE_SKILLINFO_H
#define API_BRIDGE_SKILLINFO_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class SkillInfo : public Object {
public:
    RS_OBJECT(SkillInfo)

    JACE_PROXY_API JInt getCurrentLevel();
    JACE_PROXY_API JInt getExperience();
    JACE_PROXY_API JInt getMaxLevel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_SKILLINFO_H
