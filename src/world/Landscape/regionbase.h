#ifndef REGIONBASE_H
#define REGIONBASE_H

#include "jniobject.h"

namespace world{

class RegionBase : public jni::JNIObject{
private:
    Q_DISABLE_COPY(RegionBase)
    jint globalx;
    jint globaly;
public:
    RegionBase(jobject obj) : JNIObject(obj){}
    jint getGlobalX(bool useCache = true);
    jint getGlobalY(bool useCache = true);
};

}
#endif // REGIONBASE_H
