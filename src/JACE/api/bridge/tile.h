#ifndef API_BRIDGE_TILE_H
#define API_BRIDGE_TILE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AnimableNode;
class Boundary;
class FloorDecoration;
class GroundEntity;
class WallDecoration;
class Tile : public Object {
public:
    RS_OBJECT(Tile)

    JACE_PROXY_API AnimableNode getAnimableList();
    JACE_PROXY_API Boundary getBoundary1();
    JACE_PROXY_API Boundary getBoundary2();
    JACE_PROXY_API FloorDecoration getFloorDecoration();
    JACE_PROXY_API GroundEntity getGroundEntity();
    JACE_PROXY_API JByte getPlane();
    JACE_PROXY_API WallDecoration getWallDecoration1();
    JACE_PROXY_API WallDecoration getWallDecoration2();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_TILE_H
