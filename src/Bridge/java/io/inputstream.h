#ifndef JAVA_IO_INPUTSTREAM_H
#define JAVA_IO_INPUTSTREAM_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace io {

class InputStream : public Object {
public:
    InputStream();
    InputStream(const InputStream&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit InputStream(jvalue value);
    explicit InputStream(jobject object);
    InputStream& operator = (const InputStream& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace io
} // namespace java

#endif // JAVA_IO_INPUTSTREAM_H
