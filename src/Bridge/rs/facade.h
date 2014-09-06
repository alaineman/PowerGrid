#ifndef API_BRIDGE_FACADE_H
#define API_BRIDGE_FACADE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class SkillInfo;
class Varpbits;

class Facade : public Object {
public:
    RS_OBJECT(Facade)

    JACE_PROXY_API QList<SkillInfo> getSkills();
    JACE_PROXY_API Varpbits getVarpbits();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_FACADE_H
