#ifndef API_BRIDGE_MENUITEMNODE_H
#define API_BRIDGE_MENUITEMNODE_H

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

class MenuItemNode : public NodeSub {
public:
    RS_OBJECT(MenuItemNode)

    JACE_PROXY_API String getAction();
    JACE_PROXY_API String getOption();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MENUITEMNODE_H
