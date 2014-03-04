#include "landscapedetails.h"
#include "landscape.h"
#include "tile.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(LandscapeDetails)
IMPL_RSCLASS_GET(LandscapeDetails)

IMPL_ARRAY_METHOD(LandscapeDetails, getLandscape, Landscape)
IMPL_ARRAY3_METHOD(LandscapeDetails, getRegionData, Tile)

} // namespace bridge
} // namespace api
