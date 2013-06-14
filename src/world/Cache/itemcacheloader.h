#ifndef ITEMCACHELOADER_H
#define ITEMCACHELOADER_H

#include "jniobject.h"
#include "cache.h"

namespace world{

class ItemCacheLoader : public jni::JNIObject{
private:
    Q_DISABLE_COPY(ItemCacheLoader)
    Cache* definitioncache;
    Cache* modelcache;
public:
    ItemCacheLoader(jobject obj) : JNIObject(obj){}
    Cache* getDefinitionCache(bool useCache = true);
    Cache* getModelCache(bool useCache = true);
};

}

#endif // ITEMCACHELOADER_H
