#ifndef API_BRIDGE_TOOLKITLD_H
#define API_BRIDGE_TOOLKITLD_H

#include "MethodHelper.h"
#include "graphicstoolkit.h"


namespace RS {

class CameraMatrix;
class ToolkitLD : public GraphicsToolkit {
public:
    RS_OBJECT(ToolkitLD)

    JACE_PROXY_API JFloat getAbsoluteX();
    JACE_PROXY_API JFloat getAbsoluteY();
    JACE_PROXY_API CameraMatrix getCameraMatrix();
    JACE_PROXY_API QList<JInt> getPixels();
    JACE_PROXY_API JFloat getXMultiplier();
    JACE_PROXY_API JFloat getYMultiplier();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_TOOLKITLD_H
