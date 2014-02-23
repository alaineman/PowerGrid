#ifndef API_BRIDGE_LINKEDLIST_H
#define API_BRIDGE_LINKEDLIST_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class LinkedListNode;
class LinkedList : public Object {
public:
    RS_OBJECT(LinkedList)

    JACE_PROXY_API LinkedListNode getNext();
    JACE_PROXY_API LinkedListNode getSentinel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_LINKEDLIST_H
