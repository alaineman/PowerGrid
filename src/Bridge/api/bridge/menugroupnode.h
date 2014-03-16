#ifndef API_BRIDGE_MENUGROUPNODE_H
#define API_BRIDGE_MENUGROUPNODE_H

#include "MethodHelper.h"
#include "nodesub.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
 namespace lang {
  class String;
 }
}

namespace api {
namespace bridge {

class NodeSubQueue;
class MenuGroupNode : public NodeSub {
public:
    RS_OBJECT(MenuGroupNode)

    JACE_PROXY_API NodeSubQueue getItems();
    JACE_PROXY_API String getOption();
    JACE_PROXY_API JInt getSize();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MENUGROUPNODE_H
