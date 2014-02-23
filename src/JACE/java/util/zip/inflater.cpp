#include "inflater.h"

namespace java {
namespace util {
namespace zip {

/*!
 * \class java::util::zip::Inflater
 * \brief Proxy class for \c{java.util.zip.Inflater}
 *
 * This class provides access to java Inflater objects.
 */

Inflater::Inflater() : Object() {
}

Inflater::Inflater(const Inflater &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* Inflater::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java.util.zip.Inflater");
    return &cls;
}

const jace::JClass* Inflater::getJavaJniClass() const throw (jace::JNIException) {
    return Inflater::staticGetJavaJniClass();
}

Inflater::Inflater(jobject object) :
    Object(object) {}

Inflater::Inflater(jvalue value) :
    Object(value) {}

Inflater& Inflater::operator =(const Inflater &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}
} // namespace zip
} // namespace util
} // namespace java
