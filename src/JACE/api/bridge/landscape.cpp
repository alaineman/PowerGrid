#include "landscape.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Landscape)
IMPL_RSCLASS_GET(Landscape)

IMPL_ARRAY2_METHOD(Landscape, getLocalTileHeights, JInt)

} // namespace bridge
} // namespace api
