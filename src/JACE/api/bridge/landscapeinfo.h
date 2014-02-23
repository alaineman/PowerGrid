#ifndef API_BRIDGE_LANDSCAPEINFO_H
#define API_BRIDGE_LANDSCAPEINFO_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class BaseInfo;
class GroundBytes;
class LandscapeDetails;
class ObjectDefLoader;
class LandscapeInfo : public Object {
public:
    RS_OBJECT(LandscapeInfo)

    JACE_PROXY_API BaseInfo getBaseInfo();
    JACE_PROXY_API GroundBytes getGroundBytes();
    JACE_PROXY_API LandscapeDetails getLandscapeDetails();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api


#endif // API_BRIDGE_LANDSCAPEINFO_H
