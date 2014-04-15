#ifndef API_BRIDGE_TOOLKITOPENGL_H
#define API_BRIDGE_TOOLKITOPENGL_H

#include "MethodHelper.h"
#include "graphicstoolkit.h"
using namespace java::lang;

namespace api {
namespace bridge {

class CameraMatrix;
class ToolkitOpenGL : public GraphicsToolkit {
public:
    RS_OBJECT(ToolkitOpenGL)

    /**
     * \brief the CameraMatrix associated with the camera position.
     */
    JACE_PROXY_API CameraMatrix getCameraMatrix();
    JACE_PROXY_API JFloat getAbsoluteX();
    JACE_PROXY_API JFloat getAbsoluteY();
    JACE_PROXY_API JFloat getXMultiplier();
    JACE_PROXY_API JFloat getYMultiplier();
    JACE_PROXY_API Object getOpenGLEngine();
    JACE_PROXY_API JInt getPixelFormat();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_TOOLKITOPENGL_H
