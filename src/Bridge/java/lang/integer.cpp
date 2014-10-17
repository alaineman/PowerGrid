#include "integer.h"

#include "java/lang/class.h"
#include "java/lang/string.h"

namespace java {
namespace lang {

Integer::Integer() : Number(), _val(0) {}
Integer::Integer(jint value) : Number(), _val(value) {
    JNIEnv* env = jace::helper::attach();
    jclass intClass = getJavaJniClass()->getClass();
    jmethodID constructor = env->GetMethodID(intClass, "<init>", "(I)V");
    jobject object = env->NewObject(intClass, constructor, value);
    setJavaJniObject(object);
}
Integer::Integer(const Integer &obj) : JObject(NoOp()), Number(obj),
     _val(obj.intValue()) {
}
Integer::Integer(jvalue value) : Number(value) {
    if (!isNull()) {
        _val = Number::intValue();
    }
}
Integer::Integer(jobject object) : Number(object) {
    if (!isNull()) {
        _val = Number::intValue();
    } else {
        _val = 0;
    }
}

const jace::JClass* Integer::getJavaJniClass() const throw(jace::JNIException) {
    return Integer::staticGetJavaJniClass();
}
const jace::JClass* Integer::staticGetJavaJniClass() throw(jace::JNIException) {
    static jace::JClassImpl cls ( "java.lang.Integer" );
    return &cls;
}

Integer& Integer::operator =(const Integer& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

Integer Integer::valueOf(jint value) {
    // Just wrap the jint value, and don't really call the method.
    return value;
}
jint Integer::parseInt(String string) {
    jclass thisClass = staticGetJavaJniClass()->getClass();
    Class stringClass = Class::forName("java.lang.String");
    jmethodID mID = Class::forName("java.lang.Integer").getMethodID("parseInt", {stringClass});
    return jace::helper::attach()->CallStaticIntMethod(thisClass, mID, string.getJavaJniObject());
}
String Integer::toString(jint value) {
    jclass thisClass = staticGetJavaJniClass()->getClass();
    Class intClass = Integer::getType();
    jmethodID mID = Class::forName("java.lang.Integer").getMethodID("toString", {intClass});
    return String(jace::helper::attach()->CallStaticObjectMethod(thisClass, mID, value));
}

Class Integer::getType() {
    Class integerClass = Class::forName("java.lang.Integer");
    jclass javaClass = staticGetJavaJniClass()->getClass();
    jfieldID fID = integerClass.getFieldID("TYPE");
    JNIEnv* env = jace::helper::attach();
    return Class(static_cast<jclass>(env->GetStaticObjectField(javaClass, fID)));
}

} // namespace lang
} // namespace java
