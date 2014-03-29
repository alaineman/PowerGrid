#ifndef JAVA_AWT_GRAPHICS_H
#define JAVA_AWT_GRAPHICS_H

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
namespace awt {

class Graphics : public Object {
public:
    Graphics();
    Graphics(const Graphics& obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit Graphics(jvalue val);
    explicit Graphics(jobject obj);
    Graphics& operator = (const Graphics& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_GRAPHICS_H
