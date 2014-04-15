#include "toolkitopengl.h"
#include "cameramatrix.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ToolkitOpenGL, GraphicsToolkit)
IMPL_RSCLASS_GET(ToolkitOpenGL)

IMPL_OBJECT_METHOD(ToolkitOpenGL, getCameraMatrix, CameraMatrix)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getAbsoluteX, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getAbsoluteY, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getXMultiplier, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getYMultiplier, JFloat)
IMPL_OBJECT_METHOD(ToolkitOpenGL, getOpenGLEngine, Object)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getPixelFormat, JInt)

} // namespace bridge
} // namespace api
