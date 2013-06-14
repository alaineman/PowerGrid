#ifndef VARPS_H
#define VARPS_H

#include "jniobject.h"

namespace world{

class Varps : public jni::JNIObject{
private:
    Q_DISABLE_COPY(Varps)
    vector<jint> data;
public:
    Varps(jobject obj) : JNIObject(obj){}
    vector<jint> getData(bool useCache = true);
};

}

#endif // VARPS_H
