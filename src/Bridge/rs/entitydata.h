#ifndef API_BRIDGE_ENTITYDATA_H
#define API_BRIDGE_ENTITYDATA_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class EntityPosition;

class EntityData : public Object {
public:
    RS_OBJECT(EntityData)

    JACE_PROXY_API EntityPosition getPosition();
private:
    DECLARE_FRIENDS
};

}

#endif // API_BRIDGE_ENTITYDATA_H
