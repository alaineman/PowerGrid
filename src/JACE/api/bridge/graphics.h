#ifndef API_BRIDGE_GRAPHICS_H
#define API_BRIDGE_GRAPHICS_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
 namespace awt {
  class DisplayMode;
  class GraphicsDevice;
 }
}

namespace api {
namespace bridge {

class Graphics : public Object {
public:
    RS_OBJECT(Graphics)

    JACE_PROXY_API java::awt::DisplayMode getDisplayMode();
    JACE_PROXY_API java::awt::GraphicsDevice getGraphicsDevice();
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GRAPHICS_H
