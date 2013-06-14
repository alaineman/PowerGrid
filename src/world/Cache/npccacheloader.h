#ifndef NPCCACHELOADER_H
#define NPCCACHELOADER_H

#include "jniobject.h"
#include "cache.h"

namespace world{

class NpcCacheLoader : public jni::JNIObject{
private:
    Q_DISABLE_COPY(NpcCacheLoader)
    Cache* compositecache;
    Cache* modelcache;
public:
    NpcCacheLoader(jobject obj) : JNIObject(obj){}
    Cache* getCompositeCache(bool useCache = true);
    Cache* getModelCache(bool useCache = true);
};

}

#endif // NPCCACHELOADER_H
