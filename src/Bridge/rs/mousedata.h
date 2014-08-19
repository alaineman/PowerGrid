#ifndef API_BRIDGE_MOUSEDATA_H
#define API_BRIDGE_MOUSEDATA_H

#include "java/lang/object.h"
using namespace java::lang;

#include "MethodHelper.h"


namespace RS {

class MouseData : public Object {
public:
    RS_OBJECT(MouseData)

    JACE_PROXY_API JInt getType();
    JACE_PROXY_API JLong getTime();
    JACE_PROXY_API JInt getX();
    JACE_PROXY_API JInt getY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_MOUSEDATA_H
