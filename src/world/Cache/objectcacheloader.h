#ifndef OBJECTCACHELOADER_H
#define OBJECTCACHELOADER_H

#include "jniobject.h"
#include "cache.h"

namespace world{

class ObjectCacheLoader : public jni::JNIObject{
private:
    Q_DISABLE_COPY(ObjectCacheLoader)
    Cache* definitioncache;
public:
    ObjectCacheLoader(jobject obj) : JNIObject(obj){}
    Cache* getDefinitionCache(bool useCache = true);
};

}
#endif // OBJECTCACHELOADER_H
