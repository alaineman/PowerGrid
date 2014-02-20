#ifndef ANIMATION_H
#define ANIMATION_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Animation : public Object {
public:
    RS_OBJECT(Animation)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getShieldDisplayed();
    JACE_PROXY_API JInt getWalkingProperties();
    JACE_PROXY_API JInt getWeaponDisplayed();

private:
    DECLARE_FRIENDS
};

}
}
#endif // ANIMATION_H
