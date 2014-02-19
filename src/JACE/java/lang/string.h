#ifndef STRING_H
#define STRING_H

#include "jace/os_dep.h"
#include "jace/Namespace.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JMethod.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"

namespace java {
namespace lang {

class String : public Object {
public:
    String();
    String(const String&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit String(jvalue value);
    explicit String(jobject object);
    String(jstring string);

    String& operator = (String& obj);

    std::string toStdString() const throw(jace::JNIException);
    QString toQString() const throw(jace::JNIException);

private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
    template <typename T> friend class jace::JMethod;
};

} // end namespace lang
} // end namespace java

#endif // STRING_H
