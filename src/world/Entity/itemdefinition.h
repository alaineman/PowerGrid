#ifndef ITEMDEFINITION_H
#define ITEMDEFINITION_H

#include "jniobject.h"

namespace world{

class ItemDefinition : public jni::JNIObject {
private:
    Q_DISABLE_COPY(ItemDefinition)
    jint storevalue;
    jint equiplocation;
    jboolean membersonly;
    jni::JNIString* name;
    vector<jni::JNIString*> inventoryactions;
    vector<jni::JNIString*> groundactions;
public:
    ItemDefinition(jobject obj) : JNIObject(obj){}
    jint getStoreValue(bool useCache = true);
    jint getEquipLocation(bool useCache = true);
    jboolean isMembersOnly(bool useCache = true);
    jni::JNIString* getName(bool useCache = true);
    vector<jni::JNIString*> getInventoryActions(bool useCache = true);
    vector<jni::JNIString*> getGroundActions(bool useCache = true);
};

}

#endif // ITEMDEFINITION_H
