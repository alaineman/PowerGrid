#ifndef ITEMPILE_H
#define ITEMPILE_H

#include "renderableentity.h"

namespace world{

class ItemPile : public RenderableEntity {
private:
    Q_DISABLE_COPY(ItemPile)
    jint topid;
    jint topstacksize;
    jint middleid;
    jint middlestacksize;
    jint bottomid;
    jint bottomstacksize;
public:
    ItemPile(jobject obj) : RenderableEntity(obj){}
    jint getTopId(bool useCache = true);
    jint getTopStackSize(bool useCache = true);
    jint getMiddleId(bool useCache = true);
    jint getMiddleStackSize(bool useCache = true);
    jint getBottomId(bool useCache = true);
    jint getBottomStackSize(bool useCache = true);
};

}
#endif // ITEMPILE_H
