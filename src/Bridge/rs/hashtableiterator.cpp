#include "hashtableiterator.h"

#include "node.h"
#include "hashtable.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(HashTableIterator)
IMPL_RSCLASS_GET(HashTableIterator)

IMPL_OBJECT_METHOD(HashTableIterator, getCurrent, Node)
IMPL_OBJECT_METHOD(HashTableIterator, getPrevious, Node)
IMPL_OBJECT_METHOD(HashTableIterator, getTable, HashTable)

} // namespace bridge
