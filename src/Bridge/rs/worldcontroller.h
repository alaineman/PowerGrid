#ifndef API_BRIDGE_WORLDCONTROLLER_H
#define API_BRIDGE_WORLDCONTROLLER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class WorldController : public Object {
public:
    RS_OBJECT(WorldController)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_WORLDCONTROLLER_H
