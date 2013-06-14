#ifndef ENTITYDATA_H
#define ENTITYDATA_H

#include "jniobject.h"
#include "vector3d.h"


namespace world {

class EntityData : public jni::JNIObject {
private:
    Q_DISABLE_COPY(EntityData)
    Vector3D* position;
public:
    EntityData(jobject obj) : JNIObject(obj) {}
    Vector3D* getPosition(bool useCache = true);
};

}

#endif // ENTITYDATA_H
