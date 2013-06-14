#ifndef MAPBASE_H
#define MAPBASE_H

#include "jniobject.h"

namespace world{

class MapBase : public jni::JNIObject{
private:
    Q_DISABLE_COPY(MapBase)
    jint globalx;
    jint globaly;
public:
    MapBase(jobject obj) : JNIObject(obj){}
    jint getGlobalX(bool useCache = true);
    jint getGlobalY(bool useCache = true);
};

}
#endif // MAPBASE_H
