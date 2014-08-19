#include "cache.h"
#include "hashtable.h"
#include "queue.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Cache)
IMPL_RSCLASS_GET(Cache)

IMPL_PRIMITIVE_METHOD(Cache, getCapacity, JInt)
IMPL_OBJECT_METHOD(Cache, getHashTable, HashTable)
IMPL_PRIMITIVE_METHOD(Cache, getMaxCapacity, JInt)
IMPL_OBJECT_METHOD(Cache, getReferenceQueue, Queue)

} // namespace bridge
