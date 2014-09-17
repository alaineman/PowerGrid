#include "java_class.h"
#include "java/lang/string.h"

namespace {
    //TODO move to utility class / namespace
    template<typename T>
    jobjectArray convertToClassArray(std::initializer_list<T> list) {
        int size = list.size();
        JNIEnv* env = jace::helper::attach();
        jclass javatype = env->FindClass("java/lang/Class");
        jobjectArray arr = env->NewObjectArray(size, javatype, NULL);
        int index = 0;
        for (const T* it = list.begin(); it != list.end(); it++) {
            jobject obj = (*it).getJavaJniObject();
            env->SetObjectArrayElement(arr, index, obj);
            index++;
        }
        return arr;
    }
}

namespace java {
namespace lang {

Class::Class() : Object() {}
Class::Class(const Class &obj) :
    JObject(NoOp()), Object(obj) {}
Class::Class(jclass obj) :
    Object(obj) {}
Class::Class(jvalue val) :
    Object(val) {}

const jace::JClass* Class::getJavaJniClass() const throw(jace::JNIException) {
    return Class::staticGetJavaJniClass();
}

const jace::JClass* Class::staticGetJavaJniClass() const throw(jace::JNIException) {
    static jace::JClass cls("java/lang/Class");
    return &cls;
}

String Class::getName() const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jmethodID getName = env->GetMethodID(
                getJavaJniClass()->getClass(),
                "getName", "()Ljava/lang/String;");
    if (!getName) throw JNIException("Cannot find Class.getName()");
    jobject name = env->CallObjectMethod(getJavaJniObject(), getName);
    return String(name);
}

Object Class::getDeclaredField(String name) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jmethodID getDeclaredField = env->GetMethodID(
                getJavaJniClass()->getClass(),
                "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    if (!getDeclaredField) throw jace::JNIException("Cannot find Class.getDeclaredField(String)");
    jobject result = env->CallObjectMethod(getJavaJniObject(), getDeclaredField, name.getJavaJniObject());
    return Object(result);
}

Object Class::getDeclaredField(QString name) const throw(jace::JNIException) {
    JNIEnv *env = jace::helper::attach();
    jstring string = env->NewStringUTF(name.toLocal8Bit().constData());
    if (!string) {
        throw jace::JNIException("Could not allocate a new Java String");
    }
    return getDeclaredField(String(string));
}

Object Class::getDeclaredMethod(String name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jmethodID getDeclaredMethod = env->GetMethodID(
                getJavaJniClass()->getClass(),
                "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    if (!getDeclaredMethod) throw jace::JNIException("Cannot find Class.getDeclaredField(String)");
    jobjectArray arr = convertToJavaArray(paramTypes);
    jobject result = env->CallObjectMethod(getJavaJniObject(), getDeclaredMethod, name.getJavaJniObject(), arr);
    return Object(result);
}

Object Class::getDeclaredMethod(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    JNIEnv *env = jace::helper::attach();
    jstring string = env->NewStringUTF(name.toLocal8Bit().constData());
    if (!string) {
        throw jace::JNIException("Could not allocate a new Java String");
    }
    return getDeclaredMethod(String(string), paramTypes);
}

}
}
