#include "tile.h"
#include "animablenode.h"
#include "boundary.h"
#include "floordecoration.h"
#include "groundentity.h"
#include "walldecoration.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Tile)
IMPL_RSCLASS_GET(Tile)

IMPL_OBJECT_METHOD(Tile, getAnimableList, AnimableNode)
IMPL_OBJECT_METHOD(Tile, getBoundary1, Boundary)
IMPL_OBJECT_METHOD(Tile, getBoundary2, Boundary)
IMPL_OBJECT_METHOD(Tile, getFloorDecoration, FloorDecoration)
IMPL_OBJECT_METHOD(Tile, getGroundEntity, GroundEntity)
IMPL_PRIMITIVE_METHOD(Tile, getPlane, JByte)
IMPL_OBJECT_METHOD(Tile, getWallDecoration1, WallDecoration)
IMPL_OBJECT_METHOD(Tile, getWallDecoration2, WallDecoration)

} // namespace bridge

