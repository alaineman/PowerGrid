#ifndef API_BRIDGE_ANIMATOR_H
#define API_BRIDGE_ANIMATOR_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Animation;

class Animator : public Object {
public:
    RS_OBJECT(Animator)

    JACE_PROXY_API Animation getAnimation();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMATOR_H
