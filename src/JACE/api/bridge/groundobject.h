#ifndef API_BRIDGE_GROUNDOBJECT_H
#define API_BRIDGE_GROUNDOBJECT_H

#include "MethodHelper.h"
#include "groundentity.h"

namespace api {
namespace bridge {

class GroundObject : public GroundEntity {
public:
    RS_OBJECT(GroundObject)
private:
    DECLARE_FRIENDS
};
} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GROUNDOBJECT_H
