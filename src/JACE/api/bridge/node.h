#ifndef API_BRIDGE_NODE_H
#define API_BRIDGE_NODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Node : public Object {
public:
    RS_OBJECT(Node)

    JACE_PROXY_API JLong getID();
    JACE_PROXY_API Node getNext();
    JACE_PROXY_API Node getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NODE_H
