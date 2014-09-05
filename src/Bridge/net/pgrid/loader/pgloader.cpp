#include "pgloader.h"
using jace::JNIException;
using java::awt::Component;

namespace net {
namespace pgrid {
namespace loader {

Component PGLoader::getApplet() {
    jclass cls = staticGetJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetStaticMethodID(cls, "getApplet", "()Ljava/awt/Applet;");
    jobject result = env->CallStaticObjectMethod(cls, mID);
    return Component(result);
}

PGLoader::PGLoader() : Object() {
}
PGLoader::PGLoader(const PGLoader &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* PGLoader::staticGetJavaJniClass() throw(JNIException) {
    static jace::JClassImpl cls("net.pgrid.loader.PGLoader");
    return &cls;
}

const jace::JClass* PGLoader::getJavaJniClass() const throw(JNIException) {
    return PGLoader::staticGetJavaJniClass();
}

PGLoader::PGLoader(jobject object) :
    Object(object) {}
PGLoader::PGLoader(jvalue value) :
    Object(value) {}

PGLoader& PGLoader::operator = (const PGLoader& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace loader
} // namespace pgrid
} // namespace net
