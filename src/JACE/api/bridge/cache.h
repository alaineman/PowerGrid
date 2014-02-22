#ifndef API_BRIDGE_CACHE_H
#define API_BRIDGE_CACHE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class HashTable;
class Queue;

class Cache : public Object {
public:
    RS_OBJECT(Cache)

    JACE_PROXY_API JInt getCapacity();
    JACE_PROXY_API HashTable getHashTable();
    JACE_PROXY_API JInt getMaxCapacity();
    JACE_PROXY_API Queue getReferenceQueue();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CACHE_H
