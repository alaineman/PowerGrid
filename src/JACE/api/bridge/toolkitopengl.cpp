#include "toolkitopengl.h"
#include "cameramatrix.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ToolkitOpenGL, GraphicsToolkit)
IMPL_RSCLASS_GET(ToolkitOpenGL)

IMPL_OBJECT_METHOD(ToolkitOpenGL, getCameraMatrix, CameraMatrix)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getMaxX, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getMaxY, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getMinX, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getMinY, JFloat)
IMPL_OBJECT_METHOD(ToolkitOpenGL, getOpenGLEngine, Object)
IMPL_PRIMITIVE_METHOD(ToolkitOpenGL, getPixelFormat, JInt)

} // namespace bridge
} // namespace api
