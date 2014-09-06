#include "toolkitdirectx.h"
#include "cameramatrix.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ToolkitDirectX)
IMPL_RSCLASS_GET(ToolkitDirectX)

IMPL_PRIMITIVE_METHOD(ToolkitDirectX, getAbsoluteX, JInt)
IMPL_PRIMITIVE_METHOD(ToolkitDirectX, getAbsoluteY, JInt)
IMPL_OBJECT_METHOD(ToolkitDirectX, getCameraMatrix, CameraMatrix)
IMPL_PRIMITIVE_METHOD(ToolkitDirectX, getXMultiplier, JInt)
IMPL_PRIMITIVE_METHOD(ToolkitDirectX, getYMultiplier, JInt)

} // namespace bridge

