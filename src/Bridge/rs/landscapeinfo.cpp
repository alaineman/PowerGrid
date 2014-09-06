#include "landscapeinfo.h"
#include "baseinfo.h"
#include "groundbytes.h"
#include "landscapedetails.h"
#include "objectdefloader.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(LandscapeInfo)
IMPL_RSCLASS_GET(LandscapeInfo)

IMPL_OBJECT_METHOD(LandscapeInfo, getBaseInfo, BaseInfo)
IMPL_OBJECT_METHOD(LandscapeInfo, getGroundBytes, GroundBytes)
IMPL_OBJECT_METHOD(LandscapeInfo, getLandscapeDetails, LandscapeDetails)
IMPL_OBJECT_METHOD(LandscapeInfo, getObjectDefLoader, ObjectDefLoader)

} // namespace bridge
