#ifndef JAVA_IO_SOCKET_H
#define JAVA_IO_SOCKET_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace net {

class Socket : public Object {
public:
    Socket();
    Socket(const Socket&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit Socket(jvalue value);
    explicit Socket(jobject object);
    Socket& operator = (const Socket& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace net
} // namespace java

#endif // JAVA_IO_SOCKET_H
