#ifndef EVENTOBJECT_H
#define EVENTOBJECT_H

#include "Entity/animableentity.h"
#include "Graphic/model.h"

namespace world {

class EventObject : public AnimableEntity {
private:
    Q_DISABLE_COPY(EventObject)
    jint id;
    Model* model;
public:
    EventObject(jobject obj) : AnimableEntity(obj) {}
    jint getId(bool useCache = true);
    Model* getModel(bool useCache = true);
};

}

#endif // EVENTOBJECT_H
