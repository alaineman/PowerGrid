#ifndef JAVA_LANG_INTEGER_H
#define JAVA_LANG_INTEGER_H

#include "java/lang/number.h"

namespace java {
namespace lang {

class Integer : public Number {
private:
    jint _val;
public:
    Integer();
    Integer(jint value);
    Integer(const Integer &obj);

    explicit Integer(jvalue value);
    explicit Integer(jobject object);

    virtual const jace::JClass* getJavaJniClass() const throw(jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw(jace::JNIException);

    Integer& operator= (const Integer& obj);

    static Integer valueOf(jint value);
    static jint parseInt(String string);
    static String toString(jint value);

    /**
     * @brief The runtime Class object representing the type 'int'.
     * @return the Class for the primitive type 'int'.
     */
    static Class getType();

    operator jint() const { return _val; }
private:
    template <typename T> friend T (jace::java_cast)(const ::jace::proxy::JObject&);
};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_INTEGER_H
