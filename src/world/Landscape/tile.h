#ifndef TILE_H
#define TILE_H

#include "jniobject.h"
#include "Entity/animableentitynode.h"
#include "Entity/groundentity.h"

namespace world{

class Tile : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Tile)
    AnimableEntityNode* animableobjects;
    GroundEntity* itempile;
public:
    Tile(jobject obj) : JNIObject(obj){}
    AnimableEntityNode* getAnimableObjects(bool useCache = true);
    GroundEntity* getItemPile(bool useCache = true);
};

}

#endif // TILE_H
