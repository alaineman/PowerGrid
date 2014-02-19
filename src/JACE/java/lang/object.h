#ifndef OBJECT_H
#define OBJECT_H

#include "jace/os_dep.h"
#include "jace/Namespace.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JFieldProxy.h"
#include "jace/JMethod.h"
#include "jace/JField.h"
#include "jace/JClass.h"

/**
 * Forward declarations for the classes that this class uses.
 */
namespace java {
namespace lang {

class Object: public virtual jace::proxy::JObject {
public:
    Object();
    Object(const Object&obj);
    Object(const NoOp& noop);

    virtual const jace::JClass* getJavaJniClass() const throw (::jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (::jace::JNIException);

    explicit Object(jvalue val);
    explicit Object(jobject obj);

    Object& operator= (Object& obj);

    friend std::ostream& operator<<(std::ostream& out, Object& object);
private:
    template <typename T> friend T (jace::java_cast)(const ::jace::proxy::JObject&);
    template <typename T> friend class ::jace::JMethod;
};

}
}

#endif // OBJECT_H
