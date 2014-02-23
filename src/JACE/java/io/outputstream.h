#ifndef JAVA_IO_OUTPUTSTREAM_H
#define JAVA_IO_OUTPUTSTREAM_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JMethod.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace io {

class OutputStream : public Object {
public:
    OutputStream();
    OutputStream(const OutputStream&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit OutputStream(jvalue value);
    explicit OutputStream(jobject object);
    OutputStream& operator = (const OutputStream& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace io
} // namespace java

#endif // JAVA_IO_OUTPUTSTREAM_H
