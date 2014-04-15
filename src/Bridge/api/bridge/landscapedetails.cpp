#include "landscapedetails.h"
#include "landscape.h"
#include "tile.h"
#include "cameramatrix.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(LandscapeDetails)
IMPL_RSCLASS_GET(LandscapeDetails)

IMPL_ARRAY_METHOD(LandscapeDetails, getLandscape, Landscape)
IMPL_ARRAY3_METHOD(LandscapeDetails, getRegionData, Tile)
IMPL_OBJECT_METHOD(LandscapeDetails, getCameraMatrix, CameraMatrix)

} // namespace bridge
} // namespace api
