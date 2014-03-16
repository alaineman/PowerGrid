#include "cameramatrix.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(CameraMatrix)
IMPL_RSCLASS_GET(CameraMatrix)

IMPL_ARRAY_METHOD(CameraMatrix, getID, JFloat)

} // namespace bridge
} // namespace api
