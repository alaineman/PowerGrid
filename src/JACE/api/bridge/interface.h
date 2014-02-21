#ifndef API_BRIDGE_INTERFACE_H
#define API_BRIDGE_INTERFACE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Interface : public Object {
public:
    RS_OBJECT(Interface)

    // JACE_PROXY_API QList<InterfaceChild> getChildren();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INTERFACE_H
