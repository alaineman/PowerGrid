#include "string.h"

namespace java {
namespace lang {

String::String() : Object() {
}

String::String(const String &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* String::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java.lang.String");
    return &cls;
}

const jace::JClass* String::getJavaJniClass() const throw (jace::JNIException) {
    return String::staticGetJavaJniClass();
}

String::String(jobject object) :
    Object(object) {}

String::String(jvalue value) :
    Object(value) {}

String::String(jstring string) :
    Object(string) {}

String& String::operator =(String& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

std::string String::toStdString() const throw (jace::JNIException){
    JNIEnv* env = jace::helper::attach();
    jstring string = static_cast<jstring>(getJavaJniObject());
    const char* chars = env->GetStringUTFChars(string, NULL);
    return chars;
}

QString String::toQString() const throw (jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jstring string = static_cast<jstring>(getJavaJniObject());
    const char* chars = env->GetStringUTFChars(string, NULL);
    return QString::fromLocal8Bit(chars);
}

}
}
