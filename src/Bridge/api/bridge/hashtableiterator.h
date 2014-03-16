#ifndef API_BRIDGE_HASHTABLEITERATOR_H
#define API_BRIDGE_HASHTABLEITERATOR_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Node;
class HashTable;

class HashTableIterator : public Object {
public:
    RS_OBJECT(HashTableIterator)

    JACE_PROXY_API Node getCurrent();
    JACE_PROXY_API Node getPrevious();
    JACE_PROXY_API HashTable getTable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_HASHTABLEITERATOR_H
