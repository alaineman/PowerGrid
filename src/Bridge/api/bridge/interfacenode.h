#ifndef API_BRIDGE_INTERFACENODE_H
#define API_BRIDGE_INTERFACENODE_H

#include "MethodHelper.h"
#include "node.h"
using namespace java::lang;

namespace api {
namespace bridge {

class InterfaceNode : public Node {
public:
    RS_OBJECT(InterfaceNode)

    JACE_PROXY_API JInt getMainID();

private:
    DECLARE_FRIENDS
};


} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INTERFACENODE_H
