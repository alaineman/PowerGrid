#include "double.h"

#include "java/lang/class.h"
#include "java/lang/string.h"

namespace java {
namespace lang {

Double::Double() : Number(), _val(0) {}
Double::Double(jdouble value) : Number(), _val(value) {
    JNIEnv* env = jace::helper::attach();
    jclass c = getJavaJniClass()->getClass();
    jmethodID constructor = env->GetMethodID(c, "<init>", "(I)V");
    jobject object = env->NewObject(c, constructor, value);
    setJavaJniObject(object);
}
Double::Double(const Double &obj) : JObject(NoOp()), Number(obj),
     _val(obj.intValue()) {
}
Double::Double(jvalue value) : Number(value) {
    if (!isNull()) {
        _val = Number::intValue();
    }
}
Double::Double(jobject object) : Number(object) {
    if (!isNull()) {
        _val = Number::doubleValue();
    } else {
        _val = 0;
    }
}

const jace::JClass* Double::getJavaJniClass() const throw(jace::JNIException) {
    return Double::staticGetJavaJniClass();
}
const jace::JClass* Double::staticGetJavaJniClass() throw(jace::JNIException) {
    static jace::JClassImpl cls ( "java.lang.Double" );
    return &cls;
}

Double& Double::operator =(const Double& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

Double Double::valueOf(jdouble value) {
    // Just wrap the jdouble value, and don't really call the method.
    return value;
}
jdouble Double::parseDouble(String string) {
    jclass thisClass = staticGetJavaJniClass()->getClass();
    Class stringClass = Class::forName("java.lang.String");
    jmethodID mID = Class::get<Double>().getMethodID("parseDouble", {stringClass});
    return jace::helper::attach()->CallStaticIntMethod(thisClass, mID, string.getJavaJniObject());
}
String Double::toString(jdouble value) {
    jclass thisClass = staticGetJavaJniClass()->getClass();
    Class c = Double::getType();
    jmethodID mID = Class::get<Double>().getMethodID("toString", {c});
    return String(jace::helper::attach()->CallStaticObjectMethod(thisClass, mID, value));
}

Class Double::getType() {
    Class doubleClass = Class::get<Double>();
    jclass javaClass = staticGetJavaJniClass()->getClass();
    jfieldID fID = doubleClass.getFieldID("TYPE");
    JNIEnv* env = jace::helper::attach();
    return Class(static_cast<jclass>(env->GetStaticObjectField(javaClass, fID)));
}

} // namespace lang
} // namespace java
