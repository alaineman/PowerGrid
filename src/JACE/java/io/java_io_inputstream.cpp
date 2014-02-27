#include "inputstream.h"
using jace::JNIException;

namespace java {
namespace io {

/*!
 * \class java::io::InputStream
 * \brief Proxy class for \c java.io.InputStream
 *
 * This class provides access to java InputStream objects.
 */

InputStream::InputStream() : Object() {
}
InputStream::InputStream(const InputStream &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* InputStream::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.io.InputStream");
    return &cls;
}

const jace::JClass* InputStream::getJavaJniClass() const throw (JNIException) {
    return InputStream::staticGetJavaJniClass();
}

InputStream::InputStream(jobject object) :
    Object(object) {}
InputStream::InputStream(jvalue value) :
    Object(value) {}

InputStream& InputStream::operator =(const InputStream &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace io
} // namespace java
