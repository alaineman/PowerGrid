#include "hashtable.h"

#include "node.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(HashTable)
IMPL_RSCLASS_GET(HashTable)

IMPL_ARRAY_METHOD(HashTable, getBuckets, Node)
IMPL_PRIMITIVE_METHOD(HashTable, getCurrentIndex, JInt)
IMPL_PRIMITIVE_METHOD(HashTable, getCurrentKey, JLong)
IMPL_OBJECT_METHOD(HashTable, getLastIterated, Node)
IMPL_OBJECT_METHOD(HashTable, getLastRetrieved, Node)
IMPL_PRIMITIVE_METHOD(HashTable, getSize, JInt)

} // namespace bridge
} // namespace api
