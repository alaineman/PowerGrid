#ifndef JAVA_AWT_GRAPHICSDEVICE_H
#define JAVA_AWT_GRAPHICSDEVICE_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace awt {

class GraphicsDevice : public Object {
public:
    GraphicsDevice();
    GraphicsDevice(const GraphicsDevice&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit GraphicsDevice(jvalue value);
    explicit GraphicsDevice(jobject object);
    GraphicsDevice& operator = (const GraphicsDevice& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);

};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_GRAPHICSDEVICE_H
