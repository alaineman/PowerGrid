#ifndef ENTITY_H
#define ENTITY_H

#include "jniobject.h"
#include "entitydata.h"

namespace world {

class Entity : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Entity)
    EntityData* data;
public:
    Entity(jobject obj) : JNIObject(obj) {}
    EntityData* getData(bool useCache = true);
};

}

#endif // ENTITY_H
