#include "graphicsdevice.h"
using jace::JNIException;

namespace java {
namespace awt {

/*!
 * \class java::awt::GraphicsDevice
 * \brief Proxy class for \c{java.awt.GraphicsDevice}
 *
 * This class provides access to java AWT GraphicsDevice objects.
 */

GraphicsDevice::GraphicsDevice() : Object() {
}
GraphicsDevice::GraphicsDevice(const GraphicsDevice &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* GraphicsDevice::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.awt.GraphicsDevice");
    return &cls;
}

const jace::JClass* GraphicsDevice::getJavaJniClass() const throw (JNIException) {
    return GraphicsDevice::staticGetJavaJniClass();
}

GraphicsDevice::GraphicsDevice(jobject object) :
    Object(object) {}
GraphicsDevice::GraphicsDevice(jvalue value) :
    Object(value) {}

GraphicsDevice& GraphicsDevice::operator =(const GraphicsDevice &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}


} // namespace awt
} // namespace java
