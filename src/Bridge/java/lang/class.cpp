#include "java/lang/class.h"
#include "java/lang/string.h"

namespace {
    //TODO move to utility class / namespace
    template<typename T>
    jobjectArray convertToJavaArray(const char* type, std::initializer_list<T> list) {
        int size = list.size();
        JNIEnv* env = jace::helper::attach();
        jclass javatype = env->FindClass(type);
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

const jace::JClass* Class::staticGetJavaJniClass() throw(jace::JNIException) {
    static jace::JClassImpl cls("java/lang/Class");
    return &cls;
}

String Class::getName() const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jmethodID getName = env->GetMethodID(
                getJavaJniClass()->getClass(),
                "getName", "()Ljava/lang/String;");
    if (!getName) throw jace::JNIException("Cannot find Class.getName()");
    jobject name = env->CallObjectMethod(getJavaJniObject(), getName);
    jace::helper::catchAndThrow();
    if (!name) throw jace::JNIException("Class::getName() - JNI returned NULL for class name");
    return String(name);
}

Object Class::getDeclaredField(String name) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jmethodID getDeclaredField = env->GetMethodID(
                getJavaJniClass()->getClass(),
                "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    if (!getDeclaredField) throw jace::JNIException("Cannot find Class.getDeclaredField(String)");
    jobject result = env->CallObjectMethod(getJavaJniObject(), getDeclaredField, name.getJavaJniObject());
    if (!result) throw jace::JNIException("No such field: " % name.toQString());
    return Object(result);
}

Object Class::getDeclaredField(QString name) const throw(jace::JNIException) {
    return getDeclaredField(String::fromQString(name));
}

Object Class::getDeclaredMethod(String name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jmethodID getDeclaredMethod = env->GetMethodID(
                getJavaJniClass()->getClass(),
                "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    if (!getDeclaredMethod) throw jace::JNIException("Cannot find Class.getDeclaredField(String)");
    jobjectArray arr = convertToJavaArray("java/lang/Class", paramTypes);
    jobject result = env->CallObjectMethod(getJavaJniObject(), getDeclaredMethod, name.getJavaJniObject(), arr);
    env->DeleteLocalRef(arr);
    if(!result) throw jace::JNIException("No such method: " % name.toQString());
    return Object(result);
}

Object Class::getDeclaredMethod(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    return getDeclaredMethod(String::fromQString(name), paramTypes);
}

jmethodID Class::getMethodID(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    Object reflectedMethod = getDeclaredMethod(name, paramTypes);
    if (reflectedMethod.isNull()) {
        throw jace::JNIException("No such method");
    }
    JNIEnv* env = jace::helper::attach();
    return env->FromReflectedMethod(reflectedMethod.getJavaJniObject());
}
jmethodID Class::getMethodID(String name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    Object reflectedMethod = getDeclaredMethod(name, paramTypes);
    if (reflectedMethod.isNull()) {
        throw jace::JNIException("No such method");
    }
    JNIEnv* env = jace::helper::attach();
    return env->FromReflectedMethod(reflectedMethod.getJavaJniObject());
}
jfieldID Class::getFieldID(QString name) const throw(jace::JNIException) {
    Object reflectedField = getDeclaredField(name);
    if (reflectedField.isNull()) {
        throw jace::JNIException("No such field");
    }
    JNIEnv* env = jace::helper::attach();
    return env->FromReflectedField(reflectedField.getJavaJniObject());
}
jfieldID Class::getFieldID(String name) const throw(jace::JNIException) {
    Object reflectedField = getDeclaredField(name);
    if (reflectedField.isNull()) {
        throw jace::JNIException("No such field");
    }
    JNIEnv* env = jace::helper::attach();
    return env->FromReflectedField(reflectedField.getJavaJniObject());
}
Object Class::getStaticFieldContent(String name) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    Object field = getDeclaredField(name);
    setAccessible(field);
    Class fieldClass  = Class::forName("java.lang.reflect.Field");
    Class objectClass = Class::forName("java.lang.Object");
    jmethodID mID = fieldClass.getMethodID("get", {objectClass});
    return env->CallObjectMethod(field.getJavaJniObject(), mID, NULL);
}
Object Class::getStaticFieldContent(QString name) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    String str (env->NewStringUTF(name.toLocal8Bit().constData()));
    if (str.isNull()) {
        throw jace::JNIException("Cannot create String");
    }
    return getStaticFieldContent(str);
}
Object Class::getFieldContent(String name, Object o) const throw(jace::JNIException) {
    if (o.isNull()) throw jace::JNIException("Dereferencing null in Class::getFieldContent!");
    JNIEnv* env = jace::helper::attach();
    Object field = getDeclaredField(name);
    setAccessible(field);
    Class fieldClass  = Class::forName("java.lang.reflect.Field");
    Class objectClass = Class::forName("java.lang.Object");
    jmethodID mID = fieldClass.getMethodID("get", {objectClass});
    return env->CallObjectMethod(field.getJavaJniObject(), mID, o.getJavaJniObject());
}
Object Class::getFieldContent(QString name, Object o) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    const char* cString = name.toLocal8Bit().constData();
    String str (env->NewStringUTF(cString));
    if (str.isNull()) {
        throw jace::JNIException("Cannot create String");
    }
    return getFieldContent(str, o);
}

Class Class::asArray() const throw(jace::JNIException) {
    // Convert the name to a qualified java type name with '[' in front
    // indicating an array.
    QString name = getName().toQString();
    if (name.startsWith('[')) {
        // It is already an array type, so just append another '['
        name.prepend('[');
    } else {
        // Put L...; around the class name, and prepend '['
        name = "[L" % name % ";";
    }
    return Class::forName(name);
}

void Class::setAccessible(Object obj) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass cls = env->FindClass("java/lang/reflect/AccessibleObject");
    if (!env->IsInstanceOf(obj.getJavaJniObject(), cls)) {
        env->DeleteLocalRef(cls);
        throw jace::JNIException("setAccessible called with no AccessibleObject argument");
    }
    jmethodID mID = env->GetMethodID(cls, "setAccessible", "(Z)V");
    env->CallVoidMethod(obj.getJavaJniObject(), mID, true);
    env->DeleteLocalRef(cls);
}

Class Class::forName(String name) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass classClass = staticGetJavaJniClass()->getClass();
    jmethodID forName = env->GetStaticMethodID(classClass, "forName", "(Ljava/lang/String;)Ljava/lang/Class;");
    if (!forName) throw jace::JNIException("Cannot find static Class.forName(String)");
    jclass result = static_cast<jclass>(env->CallStaticObjectMethod(classClass, forName, name.getJavaJniObject()));
    return Class(result);
}
Class Class::forName(const QString name) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jstring string = env->NewStringUTF(name.toUtf8().constData());
    return forName(string);
}

Class Class::fromJNIClass(jclass cls) throw(jace::JNIException) {
    return Class(cls);
}
Class Class::fromJNIClass(const jace::JClass *cls) throw(jace::JNIException) {
    return Class(cls->getClass());
}

}
}
