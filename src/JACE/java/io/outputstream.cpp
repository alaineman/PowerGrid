#include "outputstream.h"
using jace::JNIException;

namespace java {
namespace io {


/*!
 * \class java::io::OutputStream
 * \brief Proxy class for \c{java.io.OutputStream}
 *
 * This class provides access to java OutputStream objects.
 */

OutputStream::OutputStream() : Object() {
}
OutputStream::OutputStream(const OutputStream &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* OutputStream::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.io.OutputStream");
    return &cls;
}

const jace::JClass* OutputStream::getJavaJniClass() const throw (JNIException) {
    return OutputStream::staticGetJavaJniClass();
}

OutputStream::OutputStream(jobject object) :
    Object(object) {}
OutputStream::OutputStream(jvalue value) :
    Object(value) {}

OutputStream& OutputStream::operator =(const OutputStream &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace io
} // namespace java
