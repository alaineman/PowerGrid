#ifndef API_BRIDGE_SKILLINFO_H
#define API_BRIDGE_SKILLINFO_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class SkillInfo : public Object {
public:
    RS_OBJECT(HintArrow)

    JACE_PROXY_API JInt getCurrentLevel();
    JACE_PROXY_API JInt getExperience();
    JACE_PROXY_API JInt getMaxLevel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_SKILLINFO_H
