#ifndef API_BRIDGE_FLOOROBJECT_H
#define API_BRIDGE_FLOOROBJECT_H

#include "MethodHelper.h"
#include "floordecoration.h"

namespace api {
namespace bridge {

class ModelLD;
class ObjectDefLoader;

class FloorObject : public FloorDecoration {
public:
    RS_OBJECT(FloorObject)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API ModelLD getModel();
    JACE_PROXY_API JDouble getLocalX();
    JACE_PROXY_API JDouble getLocalY();
    JACE_PROXY_API JInt getLocationX();
    JACE_PROXY_API JInt getLocationY();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FLOOROBJECT_H
