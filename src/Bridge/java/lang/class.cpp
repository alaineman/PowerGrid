#include "java/lang/class.h"
#include "java/lang/string.h"

namespace {
    //TODO move to utility class / namespace
    template<typename T>
    jobjectArray convertToJavaArray(QString type, std::initializer_list<T> list) {
        int size = list.size();
        JNIEnv* env = jace::helper::attach();
        jclass javatype = env->FindClass(type.toUtf8().constData());
        JNI_CHECK_AND_THROW("Failed to find class named " % type);
        jobjectArray arr = env->NewObjectArray(size, javatype, NULL);
        JNI_CHECK_AND_THROW("Failed to allocate array of type " % type);
        int index = 0;
        for (const T* it = list.begin(); it != list.end(); it++) {
            jobject obj = (*it).getJavaJniObject();
            env->SetObjectArrayElement(arr, index, obj);
            JNI_CHECK_AND_THROW("Failed to set index " % QString::number(index) % " of " % type % " array");
            index++;
        }
        return arr;
    }
}

namespace java {
namespace lang {

Class::Class() : Object() {}
Class::Class(const Class &obj) : JObject(NoOp()), Object() {
    setJavaJniObject(obj.getJavaJniObject());
}
Class::Class(jclass obj) : JObject(NoOp()), Object() {
    setJavaJniObject(obj);
}
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
    JNI_CHECK_AND_THROW("Failed to call Class.getName()");

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
    JNI_CHECK_AND_THROW("Failed to get method: " % name.toQString());
    if(!result) throw jace::JNIException("No such method: " % name.toQString());
    return Object(result);
}

Object Class::getDeclaredMethod(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    return getDeclaredMethod(String::fromQString(name), paramTypes);
}

jmethodID Class::getMethodID(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    Object reflectedMethod = getDeclaredMethod(name, paramTypes);
    jmethodID mID = jace::helper::attach()->FromReflectedMethod(reflectedMethod.getJavaJniObject());
    JNI_CHECK_AND_THROW("Could not convert Method object to jmethodID");
    return mID;
}
jmethodID Class::getMethodID(String name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException) {
    Object reflectedMethod = getDeclaredMethod(name, paramTypes);
    jmethodID mID = jace::helper::attach()->FromReflectedMethod(reflectedMethod.getJavaJniObject());
    JNI_CHECK_AND_THROW("Could not convert Method object to jmethodID");
    return mID;
}
jfieldID Class::getFieldID(QString name) const throw(jace::JNIException) {
    Object reflectedField = getDeclaredField(name);
    jfieldID fID = jace::helper::attach()->FromReflectedField(reflectedField.getJavaJniObject());
    JNI_CHECK_AND_THROW("Could not convert Field object to jfieldID");
    return fID;
}
jfieldID Class::getFieldID(String name) const throw(jace::JNIException) {
    Object reflectedField = getDeclaredField(name);
    jfieldID fID = jace::helper::attach()->FromReflectedField(reflectedField.getJavaJniObject());
    JNI_CHECK_AND_THROW("Could not convert Field object to jfieldID");
    return fID;
}
Object Class::getStaticFieldContent(String name) const throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    Object field = getDeclaredField(name);
    setAccessible(field);
    Class fieldClass  = Class::forName("java.lang.reflect.Field");
    jmethodID mID = fieldClass.getMethodID("get", {Class::get<Object>()});
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
    jmethodID mID = fieldClass.getMethodID("get", {Class::get<Object>()});
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

Object Class::invoke(Object caller, Object method, std::initializer_list<Object> params) const throw(jace::JNIException) {
    jobjectArray array = convertToJavaArray("java/lang/Object", params);
    Class methodClass  = Class::forName("java/lang/reflect/Method");
    jmethodID invokeID = methodClass.getMethodID("invoke", {Class::get<Object>(), Class::get<Object>().asArray()});
    Object result = jace::helper::attach()->CallObjectMethod(method.getJavaJniObject(), invokeID, caller.getJavaJniObject(), array);
    JNI_CHECK_AND_THROW("Failed to call Method.invoke(...)");
    return result;
}

bool Class::isInstance(Object obj) const throw(jace::JNIException) {
    jclass cls = static_cast<jclass>(getJavaJniObject());
    bool result = jace::helper::attach()->IsInstanceOf(obj.getJavaJniObject(), cls);
    JNI_CHECK_AND_THROW("Failed to invoke instanceof operator");
    return result;
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
    Class accessibleObject = Class::forName("java/lang/reflect/AccessibleObject");
    if (! accessibleObject.isInstance(obj)) {
        throw jace::JNIException("setAccessible called with no AccessibleObject argument");
    }
    jmethodID mID = accessibleObject.getMethodID("setAccessible", {Class::forName("Z")});
    env->CallVoidMethod(obj.getJavaJniObject(), mID, true);
    JNI_CHECK_AND_THROW("Failed to call AccessibleObject.setAccessible(boolean)");
}

Class Class::forName(String name) throw(jace::JNIException) {
    std::string string = name.toStdString();
    JNIEnv* env = jace::helper::attach();
    jclass cls = env->FindClass(string.c_str());
    JNI_CHECK_AND_THROW(QStringLiteral("Could not find class named ") % string.c_str());
    return cls;
}
Class Class::forName(const QString name) throw(jace::JNIException) {
    QByteArray chars = name.toUtf8();
    jclass cls = jace::helper::attach()->FindClass(chars.constData());
    JNI_CHECK_AND_THROW("Could not find class named " % name);
    return cls;
}

Class Class::findClass(String name) throw(jace::JNIException) {
    Class reflection = Class::forName("net/pgrid/loader/Reflection");
    jmethodID mID = reflection.getMethodID("findClass", {Class::get<String>()});
    jclass cls = static_cast<jclass>(jace::helper::attach()->CallStaticObjectMethod(
               static_cast<jclass>(reflection.getJavaJniObject()), mID, name.getJavaJniObject()));
    JNI_CHECK_AND_THROW("Exception invoking Reflection.findClass(" % name.toQString() % ")");
    return cls;
}
Class Class::findClass(const QString name) throw(jace::JNIException) {
    return findClass(String::fromQString(name));
}

QString Class::getClassName(Primitive p) {
    switch (p) {
    case Void:    return "java.lang.Void";
    case Byte:    return "java.lang.Byte";
    case Boolean: return "java.lang.Boolean";
    case Char:    return "java.lang.Char";
    case Short:   return "java.lang.Short";
    case Integer: return "java.lang.Integer";
    case Long:    return "java.lang.Long";
    case Double:  return "java.lang.Double";
    case Float:   return "java.lang.Float";
    }
    throw std::logic_error("Primitive value is none of the enum constants");
}

Class Class::getPrimitive(Primitive p) throw(jace::JNIException) {
    QString className = getClassName(p);
    Class cls = Class::forName(className);
    jclass jcls = static_cast<jclass>(cls.getJavaJniObject());
    jfieldID typeField = cls.getFieldID("TYPE");
    jclass typeClass = static_cast<jclass>(jace::helper::attach()->GetStaticObjectField(jcls, typeField));
    JNI_CHECK_AND_THROW("Failed to get " % className % ".TYPE field");
    return typeClass;
}

Class Class::fromJNIClass(jclass cls) throw(jace::JNIException) {
    return cls;
}
Class Class::fromJNIClass(const jace::JClass *cls) throw(jace::JNIException) {
    return cls->getClass();
}

}
}
