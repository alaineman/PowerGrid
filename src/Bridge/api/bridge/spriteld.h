#ifndef API_BRIDGE_SPRITELD_H
#define API_BRIDGE_SPRITELD_H

#include "MethodHelper.h"
#include "sprite.h"
using namespace java::lang;

namespace api {
namespace bridge {

class ToolkitLD;
class SpriteLD : public Sprite {
public:
    RS_OBJECT(SpriteLD)

    JACE_PROXY_API QList<JInt> getDimensions();
    JACE_PROXY_API ToolkitLD getToolkit();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_SPRITELD_H
