#include "number.h"

#include "java/lang/class.h"

namespace java {
namespace lang {

Number::Number() : Object(NoOp()) {}
Number::Number(jvalue value) : Object(value) {}
Number::Number(jobject object) : Object(object) {}

const jace::JClass* Number::getJavaJniClass() const throw(jace::JNIException) {
    return Number::staticGetJavaJniClass();
}
const jace::JClass* Number::staticGetJavaJniClass() throw(jace::JNIException) {
    static jace::JClassImpl cls ( "java.lang.Number" );
    return &cls;
}

Number& Number::operator = (const Number &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

jint Number::intValue() const {
    jmethodID mID = getClass().getMethodID("intValue", {});
    return jace::helper::attach()->CallIntMethod(getJavaJniObject(), mID);
}
jlong Number::longValue() const {
    jmethodID mID = getClass().getMethodID("longValue", {});
    return jace::helper::attach()->CallLongMethod(getJavaJniObject(), mID);
}
jdouble Number::doubleValue() const {
    jmethodID mID = getClass().getMethodID("doubleValue", {});
    return jace::helper::attach()->CallDoubleMethod(getJavaJniObject(), mID);
}
jfloat Number::floatValue() const {
    jmethodID mID = getClass().getMethodID("floatValue", {});
    return jace::helper::attach()->CallFloatMethod(getJavaJniObject(), mID);
}
jbyte Number::byteValue() const {
    jmethodID mID = getClass().getMethodID("byteValue", {});
    return jace::helper::attach()->CallByteMethod(getJavaJniObject(), mID);
}
jshort Number::shortValue() const {
    jmethodID mID = getClass().getMethodID("shortValue", {});
    return jace::helper::attach()->CallShortMethod(getJavaJniObject(), mID);
}

} // namespace lang
} // namespace java
