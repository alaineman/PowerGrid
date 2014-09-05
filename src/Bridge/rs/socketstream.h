#ifndef API_BRIDGE_SOCKETSTREAM_H
#define API_BRIDGE_SOCKETSTREAM_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace net {
class Socket;
}
}


namespace RS {

class InputStream;
class OutputStream;
class SocketStream : public Object {
public:
    RS_OBJECT(SocketStream)

    JACE_PROXY_API InputStream getInputStream();
    JACE_PROXY_API OutputStream getOutputStream();
    JACE_PROXY_API java::net::Socket getSocket();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_SOCKETSTREAM_H
