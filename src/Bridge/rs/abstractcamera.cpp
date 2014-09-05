#include "abstractcamera.h"

#include "abstractcameralocationdata.h"
#include "abstractcentrallocationdata.h"

namespace RS {

IMPL_JACE_CONSTRUCTORS(AbstractCamera)
IMPL_RSCLASS_GET(AbstractCamera)

IMPL_OBJECT_METHOD(AbstractCamera, getCameraLocationData, AbstractCameraLocationData)
IMPL_OBJECT_METHOD(AbstractCamera, getCentralLocationData, AbstractCentralLocationData)

}
