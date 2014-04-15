#ifndef API_BRIDGE_TOOLKITDIRECTX_H
#define API_BRIDGE_TOOLKITDIRECTX_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class CameraMatrix;

class ToolkitDirectX : public Object {
public:
    RS_OBJECT(ToolkitDirectX)

    JACE_PROXY_API JInt getAbsoluteX();
    JACE_PROXY_API JInt getAbsoluteY();
    JACE_PROXY_API CameraMatrix getCameraMatrix();
    JACE_PROXY_API JInt getXMultiplier();
    JACE_PROXY_API JInt getYMultiplier();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_TOOLKITDIRECTX_H
