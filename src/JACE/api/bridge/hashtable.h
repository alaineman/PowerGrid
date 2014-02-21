#ifndef API_BRIDGE_HASHTABLE_H
#define API_BRIDGE_HASHTABLE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Node;

class HashTable : public Object {
public:
    RS_OBJECT(HashTable)

    JACE_PROXY_API QList<Node> getBuckets();
    JACE_PROXY_API JInt getCurrentIndex();
    JACE_PROXY_API JLong getCurrentKey();
    JACE_PROXY_API Node getLastIterated();
    JACE_PROXY_API Node getLastRetrieved();
    JACE_PROXY_API JInt getSize();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_HASHTABLE_H
