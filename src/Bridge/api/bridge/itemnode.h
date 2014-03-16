#ifndef API_BRIDGE_ITEMNODE_H
#define API_BRIDGE_ITEMNODE_H

#include "MethodHelper.h"
#include "node.h"
using namespace java::lang;

namespace api {
namespace bridge {

class ItemNode : public Node {
public:
    RS_OBJECT(ItemNode)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getStackSize();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ITEMNODE_H
