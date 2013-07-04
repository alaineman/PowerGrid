#ifndef TILE_H
#define TILE_H

#include "jniobject.h"
#include "Entity/animableentitynode.h"
#include "Entity/itempile.h"

namespace world{

class Tile : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Tile)
    AnimableEntityNode* animableobjects;
    ItemPile* itempile;
    RenderableEntity* floor;
    RenderableEntity* wall1;
    RenderableEntity* wall2;
    RenderableEntity* boundary1;
    RenderableEntity* boundary2;

public:
    Tile(jobject obj) : JNIObject(obj){}
    AnimableEntityNode* getAnimableObjects(bool useCache = true);
    ItemPile* getItemPile(bool useCache = true);
    RenderableEntity* getFloorObject(bool useCache = true);
    RenderableEntity* getWallObject1(bool useCache = true);
    RenderableEntity* getWallObject2(bool useCache = true);
    RenderableEntity* getBoundaryObject1(bool useCache = true);
    RenderableEntity* getBoundaryObject2(bool useCache = true);
};

}

#endif // TILE_H
