#ifndef JAVA_AWT_DISPLAYMODE_H
#define JAVA_AWT_DISPLAYMODE_H

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

class DisplayMode : public Object {
public:
    DisplayMode();
    DisplayMode(const DisplayMode&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit DisplayMode(jvalue value);
    explicit DisplayMode(jobject object);
    DisplayMode& operator = (const DisplayMode& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_DISPLAYMODE_H
