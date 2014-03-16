#include "hashtableiterator.h"

#include "node.h"
#include "hashtable.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(HashTableIterator)
IMPL_RSCLASS_GET(HashTableIterator)

IMPL_OBJECT_METHOD(HashTableIterator, getCurrent, Node)
IMPL_OBJECT_METHOD(HashTableIterator, getPrevious, Node)
IMPL_OBJECT_METHOD(HashTableIterator, getTable, HashTable)

} // namespace bridge
} // namespace api
