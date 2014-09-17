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
 *      Class intClass = Class::forName("java.lang.Integer");
 *      Object method  = objClass.getDeclaredMethod("substring", {intClass,intClass} );
 *
 * This will look for the method: "String.substring(int, int)". Note that the Reflection API
 * makes no distinction between the primitive type "int" and the (boxed) object type "Integer".
 *
 * @author Patrick Kramer
 */
class Class : public Object, virtual JObject {
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

    static Class forName(String name) throw(jace::JNIException);
};

}
}

#endif // JAVA_CLASS_H
