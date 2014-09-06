#ifndef API_BRIDGE_SERVER_H
#define API_BRIDGE_SERVER_H

#include "MethodHelper.h"
#include "abstractserver.h"
using namespace java::lang;

namespace java {
namespace lang {
  class String;
}
}


namespace RS {

class Server : public AbstractServer {
public:
    RS_OBJECT(Server)

    JACE_PROXY_API String getActivity();
    JACE_PROXY_API String getAddress();
    JACE_PROXY_API JLong getID();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_SERVER_H
