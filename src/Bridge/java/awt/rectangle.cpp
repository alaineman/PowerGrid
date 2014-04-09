#include "rectangle.h"
#include "jace/JField.h"

namespace java {
namespace awt {


/*!
 * \class java::awt::Rectangle
 * \brief Proxy class for \c java.awt.Rectangle
 *
 * This class provides access to java AWT Rectangle objects.
 */

Rectangle::Rectangle() : Object() {
}

Rectangle::Rectangle(const Rectangle &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* Rectangle::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java.awt.Rectangle");
    return &cls;
}

const jace::JClass* Rectangle::getJavaJniClass() const throw (jace::JNIException) {
    return Rectangle::staticGetJavaJniClass();
}

Rectangle::Rectangle(jobject object) :
    Object(object) {}

Rectangle::Rectangle(jvalue value) :
    Object(value) {}

Rectangle& Rectangle::operator =(const Rectangle &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

JACE_PROXY_API JInt Rectangle::getX() {
    return jace::JField<JInt>("x").get(*this);
}

JACE_PROXY_API JInt Rectangle::getY() {
    return jace::JField<JInt>("y").get(*this);
}

JACE_PROXY_API JInt Rectangle::getWidth() {
    return jace::JField<JInt>("width").get(*this);
}

JACE_PROXY_API JInt Rectangle::getHeight() {
    return jace::JField<JInt>("height").get(*this);
}

} // namespace awt
} // namespace java
