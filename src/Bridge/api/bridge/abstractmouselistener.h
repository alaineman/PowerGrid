#ifndef API_BRIDGE_ABSTRACTMOUSELISTENER_H
#define API_BRIDGE_ABSTRACTMOUSELISTENER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

#include "java/awt/component.h"
using java::awt::Component;

namespace api {
namespace bridge {

class AbstractMouseListener : public Object {
public:
    RS_OBJECT(AbstractMouseListener)

    JACE_PROXY_API virtual JInt getClickState() { return 0; }
    JACE_PROXY_API virtual Component getTarget() { return Component(); }
    JACE_PROXY_API virtual JInt getX() { return -1; }
    JACE_PROXY_API virtual JInt getY() { return -1; }

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ABSTRACTMOUSELISTENER_H
