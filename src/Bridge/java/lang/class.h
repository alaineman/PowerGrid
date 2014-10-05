#ifndef JAVA_CLASS_H
#define JAVA_CLASS_H

#include "jace/proxy/JObject.h"
#include "java/lang/object.h"

namespace java {
namespace lang {

class String;

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
 *      Class strClass = Class::forName("java.lang.String");
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
    /**
     * @brief Finds a Java Class object by name.
     *
     * The Class should be loaded by the system ClassLoader for this method to be able to find
     * the class, as such some classes can not be found using this method (in particular RS classes).
     *
     * @param name - the name of the desired Class
     * @return the Class proxy instance with a reference to the desired class, or a null Class proxy
     *         instance if no class with the specified name has been found.
     */
    static Class forName(String name) throw(jace::JNIException);
    static Class forName(QString name) throw(jace::JNIException);


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

    /**
     * @brief Returns the class object for the given proxy type.
     *
     * @return the Class object for the specified type.
     */
    template <class ProxyType>
    static Class get() throw (jace::JNIException) {
        return fromJNIClass(ProxyType::staticGetJavaJniClass());
    }
};

}
}

#endif // JAVA_CLASS_H
