#ifndef TILEHEIGHTS_H
#define TILEHEIGHTS_H

#include "jniobject.h"

namespace world{

class TileHeights : public jni::JNIObject {
private:
    Q_DISABLE_COPY(TileHeights)
    vector< vector<jint> > heights;
public:
    TileHeights(jobject obj) : JNIObject(obj){}
    vector< vector<jint> > getHeights(bool useCache = true);
};

}

#endif // TILEHEIGHTS_H
