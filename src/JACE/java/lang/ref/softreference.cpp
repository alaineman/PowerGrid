#include "softreference.h"
using jace::JNIException;

namespace java {
namespace lang {
namespace ref {
/*!
 * \class java::lang::ref::SoftReference
 * \brief Proxy class for \c{java.lang.ref.SoftReference}
 *
 * This class provides access to java SoftReference objects and provides a
 * way to get the referenced object.
 */

SoftReference::SoftReference() : Object() {
}

SoftReference::SoftReference(const SoftReference &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* SoftReference::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.lang.ref.SoftReference");
    return &cls;
}

const jace::JClass* SoftReference::getJavaJniClass() const throw (JNIException) {
    return SoftReference::staticGetJavaJniClass();
}

SoftReference::SoftReference(jobject object) :
    Object(object) {}

SoftReference::SoftReference(jvalue value) :
    Object(value) {}

SoftReference& SoftReference::operator =(const SoftReference &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

Object SoftReference::get() const throw (JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass softReferenceClass = SoftReference::staticGetJavaJniClass()->getClass();
    if (!softReferenceClass) throw JNIException("Cannot find class \"java.lang.ref.SoftReference\"");
    jmethodID get = env->GetMethodID(softReferenceClass, "get", "()Ljava/lang/Object;");
    if (!get) throw JNIException("Cannot find method get() in java.lang.ref.SoftReference");
    return Object(env->CallObjectMethod(getJavaJniObject(), get));
}
} // namespace ref
} // namespace lang
} // namespace java
