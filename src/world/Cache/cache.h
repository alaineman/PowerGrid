#ifndef CACHE_H
#define CACHE_H

#include "jniobject.h"
#include "Datastructure/hashtable.h"

namespace world{

class Cache : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Cache)
    HashTable* table;
public:
    Cache(jobject obj) : JNIObject(obj){}
    HashTable* getTable(bool useCache = true);
};

}
#endif // CACHE_H
