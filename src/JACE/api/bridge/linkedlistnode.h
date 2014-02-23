#ifndef API_BRIDGE_LINKEDLISTNODE_H
#define API_BRIDGE_LINKEDLISTNODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class LinkedListNode : public Object {
public:
    RS_OBJECT(LinkedListNode)

    JACE_PROXY_API LinkedListNode getNext();
    JACE_PROXY_API LinkedListNode getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_LINKEDLISTNODE_H
