#ifndef JAVA_LANG_NUMBER_H
#define JAVA_LANG_NUMBER_H

#include "java/lang/object.h"

namespace java {
namespace lang {

class Number : public Object {
public:
    Number();
    explicit Number(jvalue value);
    Number(jobject object);

    virtual const jace::JClass* getJavaJniClass() const throw(jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw(jace::JNIException);

    Number& operator= (const Number &obj);

    virtual jint intValue() const;
    virtual jlong longValue() const;
    virtual jdouble doubleValue() const;
    virtual jfloat floatValue() const;
    virtual jbyte byteValue() const;
    virtual jshort shortValue() const;

};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_NUMBER_H
