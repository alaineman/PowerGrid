#include "toolkitld.h"
#include "cameramatrix.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ToolkitLD, GraphicsToolkit)
IMPL_RSCLASS_GET(ToolkitLD)

IMPL_PRIMITIVE_METHOD(ToolkitLD, getAbsoluteX, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitLD, getAbsoluteY, JFloat)
IMPL_OBJECT_METHOD(ToolkitLD, getCameraMatrix, CameraMatrix)
IMPL_ARRAY_METHOD(ToolkitLD, getPixels, JInt)
IMPL_PRIMITIVE_METHOD(ToolkitLD, getXMultiplier, JFloat)
IMPL_PRIMITIVE_METHOD(ToolkitLD, getYMultiplier, JFloat)

} // namespace bridge
} // namespace api
