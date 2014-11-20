#ifndef JAVA_CLASS_H
#define JAVA_CLASS_H

#include "jace/proxy/JObject.h"
#include "java/lang/object.h"
#include "java/lang/string.h"

namespace java {
namespace lang {

/**
 * @brief Proxy class for java.lang.Class
 *
 * This class acts as a gateway between JNI and Java Reflection, and allows reasoning
 * about objects and fields in a way similar to the Java Reflection API.
 *
 * This class makes use of C++11 initializer lists for realizing Java-style varargs functions.
 * For example, the @c getDeclaredMethod(String, std::initializer_list<Class>) function can be
 * used as follows:
 *
 *      Class strClass = Class::get<String>();
 *      Class intClass = Integer::getType();
 *      Object method  = strClass.getDeclaredMethod("substring", {intClass,intClass} );
 *
 * This will look for the method: "String.substring(int, int)". Note that the types for primitives
 * can be retrieved using the getType() function of their boxed equivalents.
 *
 * @author Patrick Kramer
 */
class Class : public Object {
public:
    /**
     * @brief The primitive Java types.
     */
    enum Primitive {
        Void    = 0, ///< The void type,    equivalent to Void.TYPE in Java
        Boolean,     ///< The boolean type, equivalent to Boolean.TYPE in Java
        Byte,        ///< The byte type,    equivalent to Byte.TYPE in Java
        Char,        ///< The char type,    equivalent to Char.TYPE in Java
        Short,       ///< The short type,   equivalent to Short.TYPE in Java
        Integer,     ///< The int type,     equivalent to Integer.TYPE in Java
        Long,        ///< The long type,    equivalent to Long.TYPE in Java
        Double,      ///< The double type,  equivalent to Double.TYPE in Java
        Float        ///< The float type,   equivalent to Float.TYPE in Java
    };

    Class();
    Class(const Class& obj);

    explicit Class(jvalue val);
    Class(jclass obj);

    virtual const jace::JClass* getJavaJniClass() const throw(jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw(jace::JNIException);

    String getName() const throw(jace::JNIException);

    Object getDeclaredField(String name)   const throw(jace::JNIException);
    Object getDeclaredField(QString name)  const throw(jace::JNIException);

    Object getDeclaredMethod(String name,  std::initializer_list<Class> paramTypes) const throw(jace::JNIException);
    Object getDeclaredMethod(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException);

    jmethodID getMethodID(QString name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException);
    jmethodID getMethodID(String name, std::initializer_list<Class> paramTypes) const throw(jace::JNIException);

    jfieldID getFieldID(QString name) const throw(jace::JNIException);
    jfieldID getFieldID(String name)  const throw(jace::JNIException);

    Object getStaticFieldContent(String name) const throw(jace::JNIException);
    Object getStaticFieldContent(QString name) const throw(jace::JNIException);

    Object getFieldContent(String name, Object o) const throw(jace::JNIException);
    Object getFieldContent(QString name, Object o) const throw(jace::JNIException);

    /**
     * @brief Invokes the given method with the provided parameters.
     *
     * The method will be invoked through the Java Reflection API, so
     * it is slightly slower than calling a method directly using plain
     * JNI code.
     *
     * The advantage of this function is, that you don't need to
     * know anything about the method in order to invoke it (other than the
     * parameters). It doesn't matter if the method is static or not, or
     * what the return type is. This method will always return a null Object
     * if the method has a void return type, the return value itself when the
     * method has an Object return type, or a boxed primitive if the method
     * returns a primitive type.
     *
     * @param caller - The Object to invoke the method on.
     * @param method - The method to invoke.
     * @param params - The parameters to invoke the method with.
     * @return         The result of the method invocation.
     */
    Object invoke(Object caller, Object method, std::initializer_list<Object> params) const throw(jace::JNIException);

    /**
     * @brief Returns whether @c obj is an instance of this Class.
     * @param obj - The Object to check
     * @return      True if @c obj is an instance of this Class,
     *              false otherwise.
     */
    bool isInstance(Object obj) const throw(jace::JNIException);

    /**
     * @brief Returns the Class Object of this type as an array.
     *
     * For example, if this Class is the String class, the
     * @c asArray() function would return the Class Object of the
     * Java type @c String[].
     *
     * Similarly, the following line of code returns the type of @c int[][]:
     *
     *     Class int2D = Integer::getType().asArray().asArray();
     *
     *
     * @return The Class Object of the array type of this type.
     */
    Class asArray() const throw(jace::JNIException);

    /**
     * @brief Disables accessibility checking for the provided Method or Field.
     * @param obj the Method or Field to disable access checks for.
     */
    static void setAccessible(Object obj) throw(jace::JNIException);

    /**
     * @brief Finds a Java Class object by name.
     *
     * The Class should be loaded by the system ClassLoader for this method to be able to find
     * the class, as such some classes can not be found using this method (in particular RS classes).
     *
     * Array classes can be retrieved by passing "[Ltype;" as argument, with "type" being the name of
     * the component type of the array. For example, @c Class::forName("[Ljava.lang.String;") returns
     * the type of String[].
     *
     * @param name - the name of the desired Class
     * @return the Class proxy instance with a reference to the desired class, or a null Class proxy
     *         instance if no class with the specified name has been found.
     */
    static Class forName(String name) throw(jace::JNIException);
    static Class forName(const QString name) throw(jace::JNIException);

    /**
     * @brief Tries to find the class with the given name.
     *
     * This function tries to find the class using the Reflection component
     * in the Java loader. Therefore, this function will work for almost all
     * classes, including RS classes.
     *
     * @param name - The name of the Class to retrieve.
     * @return       The Class with the given name.
     *
     * @throws JNIException - When no Class with the give name exists.
     */
    static Class findClass(String name) throw(jace::JNIException);
    static Class findClass(const QString name) throw(jace::JNIException);

    /**
     * @brief Returns a Java Class object corresponding to the given type.
     *
     * For example, this allows retrieval of the String class as follows:
     *
     *     Class stringClass = Class::get<String>();
     *
     * For obvious reasons, @c T must be a Java proxy class.
     *
     * @param <T> - The type of the class to retrieve.
     * @throws jace::JNIException - when an exception occurs in the JVM.
     */
    template<typename T>
    static Class get() throw(jace::JNIException) {
        jclass cls = T::staticGetJavaJniClass()->getClass();
        JNI_CHECK_AND_THROW("Failed to get Java class object");
        return Class(cls);
    }

    /**
     * @brief Returns the (boxed) Class name of the given Primitive type.
     * @param p - The Primitive to get the class name for.
     * @return
     */
    static QString getClassName(Primitive p);

    /**
     * @brief Returns the primitive Java Class object corresponding to the given type.
     *
     * For example, to get the type of 'int' (and not 'Integer'), you can do:
     *
     *     Class intClass = Class::getPrimitive(Integer);
     *
     * This is equivalent to stating (in Java):
     *
     *     Class<?> intClass = Integer.TYPE;
     *
     * @param p - The Primitive to get the type for.
     * @return    The primitive Class.
     *
     * @throws jace::JNIException - When an Exception occurs in the JVM
     */
    static Class getPrimitive(Primitive p) throw(jace::JNIException);

    /**
     * @brief Returns a Class object that references the provided JNI class.
     * @param cls - the JNI jclass representing the class.
     * @return a Class object for the provided jclass.
     */
    static Class fromJNIClass(jclass cls) throw(jace::JNIException);
    /**
     * @brief Returns a Class object that references the provided JACE class.
     * @param cls - the JACE JClass representing the class.
     * @return a Class object for the provided jclass.
     */
    static Class fromJNIClass(const jace::JClass* cls) throw(jace::JNIException);

};

}
}

#endif // JAVA_CLASS_H
