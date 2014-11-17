#include "pgloader.h"

using jace::JNIException;
using java::awt::Component;

#include "java/lang/class.h"
using namespace java::lang;

#include "jace/JArray.h"
using jace::JArray;

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
    static jace::JClassImpl cls("net/pgrid/loader/PowerGrid");
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

void PGLoader::start() throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    Class pgClass = Class::get<PGLoader>();
    Class stringArray = Class::get<String>().asArray();
    Object method = pgClass.getDeclaredMethod("main", {stringArray} );
    if (method.isNull()) {
        throw JNIException("Method 'main' not found");
    }
    jmethodID mID = env->FromReflectedMethod(method);
    env->CallStaticVoidMethod(static_cast<jclass>(pgClass.getJavaJniObject()), mID, NULL);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        throw JNIException("Java Exception in PGLoader::main()");
    }
}

} // namespace loader
} // namespace pgrid
} // namespace net
