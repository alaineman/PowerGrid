#include "spriteld.h"
#include "toolkitld.h"

namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(SpriteLD, Sprite)
IMPL_RSCLASS_GET(SpriteLD)

IMPL_ARRAY_METHOD(SpriteLD, getDimensions, JInt)
IMPL_OBJECT_METHOD(SpriteLD, getToolkit, ToolkitLD)

} // namespace bridge

