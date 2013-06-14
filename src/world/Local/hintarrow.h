#ifndef HINTARROW_H
#define HINTARROW_H

#include "jniobject.h"

namespace world{

class HintArrow : public jni::JNIObject{
private:
    Q_DISABLE_COPY(HintArrow)
    jint localx;
    jint localy;
    jint plane;
    jint type;
    jint targetindex;
public:
    HintArrow(jobject obj) : JNIObject(obj){}
    jint getLocalX(bool useCache = true);
    jint getLocalY(bool useCache = true);
    jint getPlane(bool useCache = true);
    jint getType(bool useCache = true);
    jint getTargetIndex(bool useCache = true);

};

}

#endif // HINTARROW_H
