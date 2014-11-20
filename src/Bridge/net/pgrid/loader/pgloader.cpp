#include "pgloader.h"

using jace::JNIException;
using java::awt::Component;
using std::initializer_list;

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

void PGLoader::start(const std::initializer_list<QString> args) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    Class stringCls = Class::get<String>();
    jobjectArray arr = env->NewObjectArray(args.size(), static_cast<jclass>(stringCls.getJavaJniObject()), NULL);
    JNI_CHECK_AND_THROW("Failed to create new String array");

    initializer_list<QString>::iterator it = args.begin();
    for (jsize i=0; it != args.end(); i++, it++) {
        jstring obj = String::fromQString(*it);
        env->SetObjectArrayElement(arr, i, obj);
        JNI_CHECK_AND_THROW("Failed to put argument " % *it % " into array at position " % QString::number(i));
    }

    Class pgClass = Class::get<PGLoader>();
    jclass stringArrayClass = env->GetObjectClass(arr);
    JNI_CHECK_AND_THROW("Cannot find Class of String[] object");
    jmethodID mID = pgClass.getMethodID("main", {Class::fromJNIClass(stringArrayClass)} );
    env->CallStaticVoidMethod(static_cast<jclass>(pgClass.getJavaJniObject()), mID, arr);
    JNI_CHECK_AND_THROW("Exception in Java client");
    env->DeleteLocalRef(stringArrayClass);
}

jint PGLoader::computeClientHash() throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    Class pgClass = Class::get<PGLoader>();
    jmethodID mID = pgClass.getMethodID("computeClientHash", {});
    jint result = env->CallStaticIntMethod(static_cast<jclass>(pgClass.getJavaJniObject()), mID);
    JNI_CHECK_AND_THROW("Failed to invoke PowerGrid.computeClientHash()");
    return result;
}

Class PGLoader::findClass(QString name) throw(jace::JNIException) {
    JNIEnv* env    = jace::helper::attach();
    String jName   = String::fromQString(name);
    Class pgLoader = Class::get<PGLoader>();
    jmethodID mID  = pgLoader.getMethodID("findClass", {Class::get<String>()});
    jobject result = env->CallStaticObjectMethod(static_cast<jclass>(pgLoader.getJavaJniObject()), mID, jName.getJavaJniObject());
    JNI_CHECK_AND_THROW("Failed to invoke PowerGrid.findClass(String)");
    return Class(static_cast<jclass>(result));
}

} // namespace loader
} // namespace pgrid
} // namespace net
