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
    class Factory  {
    public:
        static Object create();
    };
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

    template <typename T> friend class ::jace::ElementProxy;
    template <typename T> friend class ::jace::JFieldProxy;
    template <typename T> friend class ::jace::JMethod;
};

}
}

namespace jace {

template <> class ElementProxy<java::lang::Object> : public java::lang::Object {
public:
    ElementProxy(jarray array, jvalue element, int index);
    ElementProxy(const jace::ElementProxy<java::lang::Object>& proxy);
private:
    jarray parent;
    int mIndex;
};

template <> class JFieldProxy<java::lang::Object> : public java::lang::Object {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<java::lang::Object>& object );
    java::lang::Object& operator=( const java::lang::Object& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

}

#endif // OBJECT_H
