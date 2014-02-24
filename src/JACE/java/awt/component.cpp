#include "component.h"
using jace::JNIException;

namespace java {
namespace awt {

/*!
 * \class java::awt::Component
 * \brief Proxy class for \c{java.awt.Component}
 *
 * This class provides access to java AWT Component objects.
 */

Component::Component() : Object() {
}
Component::Component(const Component &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* Component::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.awt.Component");
    return &cls;
}

const jace::JClass* Component::getJavaJniClass() const throw (JNIException) {
    return Component::staticGetJavaJniClass();
}

Component::Component(jobject object) :
    Object(object) {}
Component::Component(jvalue value) :
    Object(value) {}

Component& Component::operator =(const Component &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace awt
} // namespace java
