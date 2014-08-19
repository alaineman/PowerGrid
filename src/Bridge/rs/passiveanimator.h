#ifndef API_BRIDGE_PASSIVEANIMATOR_H
#define API_BRIDGE_PASSIVEANIMATOR_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class PassiveAnimator : public Object {
public:
    RS_OBJECT(PassiveAnimator)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_PASSIVEANIMATOR_H
