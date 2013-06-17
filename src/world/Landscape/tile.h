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
public:
    Tile(jobject obj) : JNIObject(obj){}
    AnimableEntityNode* getAnimableObjects(bool useCache = true);
    ItemPile* getItemPile(bool useCache = true);
};

}

#endif // TILE_H
