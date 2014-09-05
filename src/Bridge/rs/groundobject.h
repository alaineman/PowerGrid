#ifndef API_BRIDGE_GROUNDOBJECT_H
#define API_BRIDGE_GROUNDOBJECT_H

#include "MethodHelper.h"
#include "groundentity.h"


namespace RS {

class GroundObject : public GroundEntity {
public:
    RS_OBJECT(GroundObject)
private:
    DECLARE_FRIENDS
};
} // namespace bridge

#endif // API_BRIDGE_GROUNDOBJECT_H
