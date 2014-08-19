#include "cameralocationdata.h"
#include "entityposition.h"
#include "quaternion.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(CameraLocationData, AbstractCameraLocationData)
IMPL_RSCLASS_GET(CameraLocationData)

IMPL_OBJECT_METHOD(CameraLocationData, getPoint1, EntityPosition)
IMPL_OBJECT_METHOD(CameraLocationData, getPoint2, EntityPosition)
IMPL_OBJECT_METHOD(CameraLocationData, getQuaternion, Quaternion)

} // namespace bridge
