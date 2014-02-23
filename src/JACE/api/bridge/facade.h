#ifndef API_BRIDGE_FACADE_H
#define API_BRIDGE_FACADE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class SkillInfo;
class Varpbits;

class Facade : public Object {
public:
    RS_OBJECT(Facade)

    JACE_PROXY_API QList<SkillInfo> getSkills();
    JACE_PROXY_API Varpbits getVarpbits();
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FACADE_H
