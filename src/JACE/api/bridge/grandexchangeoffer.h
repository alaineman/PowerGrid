#ifndef API_BRIDGE_GRANDEXCHANGEOFFER_H
#define API_BRIDGE_GRANDEXCHANGEOFFER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class GrandExchangeOffer : public Object {
public:
    RS_OBJECT(GrandExchangeOffer)

    JACE_PROXY_API JLong getID();
    JACE_PROXY_API JInt getPrice();
    JACE_PROXY_API JInt getSpent();
    JACE_PROXY_API JByte getState();
    JACE_PROXY_API JInt getTotal();
    JACE_PROXY_API JInt getTransferred();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GRANDEXCHANGEOFFER_H
