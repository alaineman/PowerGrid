#include "socketstream.h"
#include "inputstream.h"
#include "outputstream.h"
#include "java/net/socket.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(SocketStream)
IMPL_RSCLASS_GET(SocketStream)

IMPL_OBJECT_METHOD(SocketStream, getInputStream, InputStream)
IMPL_OBJECT_METHOD(SocketStream, getOutputStream, OutputStream)
IMPL_OBJECT_METHOD(SocketStream, getSocket, java::net::Socket)

} // namespace bridge

