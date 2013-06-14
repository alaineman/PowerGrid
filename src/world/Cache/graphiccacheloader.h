#ifndef GRAPHICCACHELOADER_H
#define GRAPHICCACHELOADER_H

#include "jniobject.h"
#include "cache.h"

namespace world{

class GraphicCacheLoader : public jni::JNIObject{
private:
    Q_DISABLE_COPY(GraphicCacheLoader)
    Cache* graphiccache;
    Cache* modelcache;
public:
    GraphicCacheLoader(jobject obj) : JNIObject(obj){}
    Cache* getGraphicCache(bool useCache = true);
    Cache* getModelCache(bool useCache = true);
};

}

#endif // GRAPHICCACHELOADER_H
