#include "object.h"

namespace java {
namespace lang {

Object::Object() :
    JObject() {}

Object::Object(const NoOp &noop) :
    JObject(noop) {}

Object::Object(const Object &obj) :
    JObject(obj.getJavaJniValue()) {}

Object::Object(jobject obj) :
    JObject(obj) {}

Object::Object(jvalue val) :
    JObject(val) {}

const jace::JClass* Object::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java.lang.Object");
    return &cls;
}

const jace::JClass* Object::getJavaJniClass() const throw(jace::JNIException) {
    return Object::staticGetJavaJniClass();
}

Object& Object::operator =(Object& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // end namespace lang
} // end namespace java

std::ostream& operator<<(std::ostream& out, java::lang::Object& object) {
    return out << jace::helper::toString(object.getJavaJniObject());
}

