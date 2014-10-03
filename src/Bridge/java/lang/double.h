#ifndef JAVA_LANG_DOUBLE_H
#define JAVA_LANG_DOUBLE_H

#include "java/lang/number.h"

namespace java {
namespace lang {

class Double : public Number {
private:
    jdouble _val;
public:
    Double();
    Double(jdouble value);
    Double(const Double &obj);

    explicit Double(jvalue value);
    explicit Double(jobject object);

    virtual const jace::JClass* getJavaJniClass() const throw(jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw(jace::JNIException);

    Double& operator= (const Double& obj);

    static Double valueOf(jdouble value);
    static jdouble parseDouble(String string);
    static String toString(jdouble value);

    virtual jdouble doubleValue() const { return _val; }

    /**
     * @brief The runtime Class object representing the type 'double'.
     *
     * The result of this function is equivalent to the contents of the field named
     * "TYPE" in the Double class.
     *
     * @return the Class for the primitive type 'double'.
     */
    static Class getType();

    operator jdouble() const { return _val; }
private:
    template <typename T> friend T (jace::java_cast)(const ::jace::proxy::JObject&);
};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_DOUBLE_H
