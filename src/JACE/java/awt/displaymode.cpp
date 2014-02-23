#include "displaymode.h"
using jace::JNIException;

namespace java {
namespace awt {

/*!
 * \class java::awt::DisplayMode
 * \brief Proxy class for \c{java.awt.DisplayMode}
 *
 * This class provides access to java AWT DisplayMode objects.
 */

DisplayMode::DisplayMode() : Object() {
}
DisplayMode::DisplayMode(const DisplayMode &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* DisplayMode::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.awt.DisplayMode");
    return &cls;
}

const jace::JClass* DisplayMode::getJavaJniClass() const throw (JNIException) {
    return DisplayMode::staticGetJavaJniClass();
}

DisplayMode::DisplayMode(jobject object) :
    Object(object) {}
DisplayMode::DisplayMode(jvalue value) :
    Object(value) {}

DisplayMode& DisplayMode::operator =(const DisplayMode &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}


} // namespace awt
} // namespace java
