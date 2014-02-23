#include "socket.h"
using jace::JNIException;

namespace java {
namespace io {

/*!
 * \class java::io::Socket
 * \brief Proxy class for \c{java.io.Socket}
 *
 * This class provides access to java Socket objects.
 */

Socket::Socket() : Object() {
}
Socket::Socket(const Socket &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* Socket::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.io.Socket");
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

} // namespace io
} // namespace java
