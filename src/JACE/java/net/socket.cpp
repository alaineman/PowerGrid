#include "socket.h"
using jace::JNIException;

namespace java {
namespace net {

/*!
 * \class java::net::Socket
 * \brief Proxy class for \c{java.net.Socket}
 *
 * This class provides access to java Socket objects.
 */

Socket::Socket() : Object() {
}
Socket::Socket(const Socket &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* Socket::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.net.Socket");
    return &cls;
}

const jace::JClass* Socket::getJavaJniClass() const throw (JNIException) {
    return Socket::staticGetJavaJniClass();
}

Socket::Socket(jobject object) :
    Object(object) {}
Socket::Socket(jvalue value) :
    Object(value) {}

Socket& Socket::operator =(const Socket &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace net
} // namespace java
