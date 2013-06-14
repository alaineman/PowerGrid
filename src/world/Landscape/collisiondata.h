#ifndef COLLISIONDATA_H
#define COLLISIONDATA_H

#include "jniobject.h"

namespace world{

class CollisionData : public jni::JNIObject {
private:
    Q_DISABLE_COPY(CollisionData)
    vector<vector<jint> > flags;
public:
    CollisionData(jobject obj) : JNIObject(obj){}
    vector<vector<jint> > getFlags(bool useCache = true);
};

}
#endif // COLLISIONDATA_H
