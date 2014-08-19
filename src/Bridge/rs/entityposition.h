#ifndef API_BRIDGE_ENTITYPOSITION_H
#define API_BRIDGE_ENTITYPOSITION_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class EntityPosition : public Object {
public:
    RS_OBJECT(EntityPosition)

    JACE_PROXY_API JFloat getHeight();
    JACE_PROXY_API JFloat getLocalX();
    JACE_PROXY_API JFloat getLocalY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_ENTITYPOSITION_H
