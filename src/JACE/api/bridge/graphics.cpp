#include "graphics.h"
#include "java/awt/displaymode.h"
#include "java/awt/graphicsdevice.h"
using namespace java::awt;

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Graphics)
IMPL_RSCLASS_GET(Graphics)

IMPL_OBJECT_METHOD(Graphics, getDisplayMode, DisplayMode)
IMPL_OBJECT_METHOD(Graphics, getGraphicsDevice, GraphicsDevice)

} // namespace bridge
} // namespace api
