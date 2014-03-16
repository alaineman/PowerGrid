#ifndef JAVA_AWT_COMPONENT_H
#define JAVA_AWT_COMPONENT_H

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

/*!
 * \brief Proxy class for \c java.awt.Component
 *
 * This class provides access to java AWT Component objects.
 */

class Component : public Object {
public:
    Component();
    Component(const Component&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit Component(jvalue value);
    explicit Component(jobject object);
    Component& operator = (const Component& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_COMPONENT_H
