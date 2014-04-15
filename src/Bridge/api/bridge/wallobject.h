#ifndef API_BRIDGE_WALLOBJECT_H
#define API_BRIDGE_WALLOBJECT_H

#include "MethodHelper.h"
#include "walldecoration.h"

namespace api {
namespace bridge {

class ModelLD;
class ObjectDefLoader;
class WallObject : public WallDecoration {
public:
    RS_OBJECT(WallObject)

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

#endif // API_BRIDGE_WALLOBJECT_H
