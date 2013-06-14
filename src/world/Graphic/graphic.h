#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "jniobject.h"

namespace world{

class Graphic : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Graphic)
    jint id;
public:
    Graphic(jobject obj) : JNIObject(obj){}
    jint getId(bool useCache = true);
};

}

#endif // GRAPHIC_H
