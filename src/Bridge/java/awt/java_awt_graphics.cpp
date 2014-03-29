#include "graphics.h"
using jace::JNIException;

namespace java {
namespace awt {

Graphics::Graphics() : Object() {
}
Graphics::Graphics(const Graphics &obj) :
    JObject( NoOp() ), Object(obj) {
}

const jace::JClass* Graphics::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.awt.Graphics");
    return &cls;
}
const jace::JClass* Graphics::getJavaJniClass() const throw (JNIException) {
    return Graphics::staticGetJavaJniClass();
}

Graphics::Graphics(jobject obj) :
    Object(obj) {
}
Graphics::Graphics(jvalue val) :
    Object(val) {
}

Graphics& Graphics::operator =(const Graphics& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace awt
} // namespace java
