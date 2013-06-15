#ifndef ITEMDEFINITION_H
#define ITEMDEFINITION_H

#include "jniobject.h"

namespace world{

class ItemDefinition : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ItemDefinition)
public:
    ItemDefinition(jobject obj) : JNIObject(obj){}
};

}

#endif // ITEMDEFINITION_H
